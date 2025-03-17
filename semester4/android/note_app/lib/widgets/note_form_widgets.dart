import 'package:flutter/material.dart';

class NoteFormWidget extends StatelessWidget {
  final bool isImportant;
  final int number;
  final String title;
  final String description;
  final ValueChanged<bool> onChangedIsImportant;
  final ValueChanged<int> onChangedNumber;
  final ValueChanged<String> onChangeTitle;
  final ValueChanged<String> onChangeDescription;

  const NoteFormWidget({
    super.key,
    required this.isImportant,
    required this.number,
    required this.title,
    required this.description,
    required this.onChangedIsImportant,
    required this.onChangedNumber,
    required this.onChangeTitle,
    required this.onChangeDescription,
  });

  @override
  Widget build(BuildContext context) {
    return SingleChildScrollView(
      child: Padding(
        padding: const EdgeInsets.all(16),
        child: Column(
          children: [
            Row(
              children: [
                Switch(value: isImportant, onChanged: onChangedIsImportant),
                Expanded(
                  child: Slider(
                    value: number.toDouble(),
                    min: 0,
                    max: 5,
                    divisions: 5,
                    onChanged: (value) => onChangedNumber(value.toInt()),
                  ),
                ),
              ],
            ),
            buildTitleField(),
            const SizedBox(height: 8),
            buildDescriptionField(),
          ],
        ),
      ),
    );
  }

  buildTitleField() {
    return TextFormField(
      maxLines: 1,
      initialValue: title,
      onChanged: onChangeTitle,
      validator:
          (title) =>
              title != null && title.isEmpty
                  ? 'The title cannot be empty'
                  : null,
      decoration: InputDecoration(
        border: InputBorder.none,
        hintText: 'Title',
        hintStyle: TextStyle(color: Colors.grey),
      ),
    );
  }

  buildDescriptionField() {
    return TextFormField(
      maxLines: null,
      initialValue: description,
      style: TextStyle(fontWeight: FontWeight.bold, fontSize: 24),
      onChanged: onChangeDescription,
      decoration: InputDecoration(
        border: InputBorder.none,
        hintText: 'Type something...',
        hintStyle: TextStyle(color: Colors.grey),
      ),
      validator:
          (description) =>
              description != null && description.isEmpty
                  ? 'The description cannot be empty'
                  : null,
    );
  }
}
