

import 'package:flutter/material.dart';
import 'package:news_app/response_articles.dart';

class DetailNewsPage extends StatelessWidget {
  final Article article;
  const DetailNewsPage({super.key, required this.article});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: ListView(
        children: [
          Image.network(article.urlToImage),
          Text(article.description)
        ],
      ),
    );
  }
}