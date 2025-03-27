import 'package:flutter/material.dart';

class PostWidget extends StatelessWidget {
  final Map<String, String> post;
  const PostWidget({Key? key, required this.post}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        // Post header: avatar, username, location, and more icon
        Padding(
          padding: const EdgeInsets.all(8.0),
          child: Row(
            children: [
              CircleAvatar(
                backgroundImage: AssetImage(post['avatar']!),
              ),
              SizedBox(width: 8),
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      post['username'] ?? '',
                      style: TextStyle(fontWeight: FontWeight.bold),
                    ),
                    if (post['location'] != null && post['location']!.isNotEmpty)
                      Text(
                        post['location']!,
                        style: TextStyle(color: Colors.grey, fontSize: 12),
                      ),
                  ],
                ),
              ),
              Icon(Icons.more_vert),
            ],
          ),
        ),

        // Post image (full width, no empty space)
        SizedBox(
          width: double.infinity,
          child: Image.asset(
            post['image'] ?? '',
            fit: BoxFit.cover,
          ),
        ),

        // Post actions
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 8.0, vertical: 8.0),
          child: Row(
            children: [
              Icon(Icons.favorite_border),
              SizedBox(width: 16),
              Icon(Icons.chat_bubble_outline),
              SizedBox(width: 16),
              Icon(Icons.send),
              Spacer(),
              Icon(Icons.bookmark_border),
            ],
          ),
        ),

        // Likes
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 8.0),
          child: Text(
            'Liked by adrian1 and ${post['likes'] ?? '0'} others',
            style: TextStyle(fontWeight: FontWeight.bold),
          ),
        ),

        // Caption
        if (post['caption'] != null && post['caption']!.isNotEmpty)
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 8.0, vertical: 4.0),
            child: RichText(
              text: TextSpan(
                style: TextStyle(color: Colors.black),
                children: [
                  TextSpan(
                    text: post['username'] ?? '',
                    style: TextStyle(fontWeight: FontWeight.bold),
                  ),
                  TextSpan(text: '  '),
                  TextSpan(text: post['caption'] ?? ''),
                ],
              ),
            ),
          ),
        SizedBox(height: 16),
      ],
    );
  }
}
