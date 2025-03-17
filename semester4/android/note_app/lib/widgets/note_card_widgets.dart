import 'package:flutter/material.dart';
import 'package:intl/intl.dart';
import 'package:note_app/models/note.dart';

final _lightColors = [
  Colors.amber.shade300,
  Colors.lightBlue.shade300,
  Colors.lightGreen.shade300,
  Colors.orange.shade300,
  Colors.pinkAccent.shade100,
  Colors.tealAccent.shade100,
];

class NoteCardWidget extends StatelessWidget {
  final Note note;
  final int index;
  const NoteCardWidget({super.key, required this.note, required this.index});

  @override
  Widget build(BuildContext context) {
    final time = DateFormat.yMMMd().add_jms().format(note.createdTime);
    final minHeight = getMinHeight(index);
    final color = _lightColors[index % _lightColors.length];

    return Card(
      color: color,
      child: Container(
        constraints: BoxConstraints(minHeight: minHeight),
        padding: const EdgeInsets.all(8),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(time, style: TextStyle(color: Colors.grey.shade700),),
            const SizedBox(height: 8),
            Text(
              note.title,
              style: const TextStyle(
                fontSize: 20,
                fontWeight: FontWeight.bold,
              ),
            ),
            const SizedBox(height: 8),
            Text(note.description, style: const TextStyle(fontSize: 18)),
          ],
        ),
      ),
    );
  }

  double getMinHeight(int index) {
    switch (index % 4) {
      case 0:
        return 100;
      case 1:
        return 150;
      case 2:
        return 200;
      case 3:
        return 100;
      default:
        return 100;
    }
  }
}
