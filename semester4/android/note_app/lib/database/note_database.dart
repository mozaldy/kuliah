import 'package:note_app/models/note.dart';
import 'package:path/path.dart';
import 'package:sqflite/sqflite.dart';

class NoteDatabase {
  static final NoteDatabase instance = NoteDatabase._init();

  NoteDatabase._init();

  static Database? _database;

  Future<Database> get database async {
    if (_database != null) return _database!;
    _database = await _initDB('notes.db');
    return _database!;
  }

  Future<Database> _initDB(String filePath) async {
    final dbPath = await getDatabasesPath();
    final path = join(dbPath, filePath);
    return await openDatabase(path, version: 1, onCreate: _createDB);
  }

  Future _createDB(Database db, int version) async {
    const sql = '''
    CREATE TABLE $tableNotes(
    ${NoteFields.id} INTEGER PRIMARY KEY AUTOINCREMENT,
    ${NoteFields.isImportant} BOOLEAN NOT NULL,
    ${NoteFields.number} INTEGER NOT NULL,
    ${NoteFields.title} TEXT NOT NULL,
    ${NoteFields.description} TEXT NOT NULL,
    ${NoteFields.time} TEXT NOT NULL
    )
    ''';

    await db.execute(sql);
  }

  Future<Note> create(Note note) async {
    final db = await instance.database;
    final id = await db.insert(tableNotes, note.toJson());
    return note.copy(id: id);
  }

  Future<List<Note>> getAllNotes() async {
    final db = await instance.database;
    final result = await db.query(tableNotes);
    return result.map((json) => Note.fromJson(json)).toList();
  }

  Future<Note> getNoteById(int id) async {
    final db = await instance.database;
    final result = await db.query(tableNotes, where: '${NoteFields.id} = ?', whereArgs: [id]);
    if (result.isNotEmpty) {
      return Note.fromJson(result.first);
    } else {
      throw Exception('Note with id $id not found');
    }
  }

  Future<int> deleteNoteById(int id) async {
    final db = await instance.database;
    return await db.delete(tableNotes, where: '${NoteFields.id} = ?', whereArgs: [id]);
  }

  Future<int> updateNote(Note note) async {
    final db = await instance.database;
    return await db.update(tableNotes, note.toJson(), where: '${NoteFields.id} = ?', whereArgs: [note.id]);
  }
}