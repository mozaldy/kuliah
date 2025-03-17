import 'dart:convert';

ResponseArticles responseArticleFromJson(String str) =>
    ResponseArticles.fromJson(json.decode(str));

class ResponseArticles {
  final String status;
  final int totalResults;
  final List<Article> articles;

  ResponseArticles({
    required this.status,
    required this.totalResults,
    required this.articles,
  });

  factory ResponseArticles.fromJson(Map<String, dynamic> json) =>
      ResponseArticles(
        status: json["status"],
        totalResults: json["totalResults"],
        articles: List<Article>.from(
          json["articles"].map((x) => Article.fromJson(x)),
        ),
      );

  Map<String, dynamic> toJson() => {
    "status": status,
    "totalResults": totalResults,
    "articles": List<dynamic>.from(articles.map((x) => x.toJson())),
  };
}

class Article {
  final Source source;
  final String author;
  final String title;
  final String description;
  final String url;
  final String urlToImage;
  final DateTime publishedAt;
  final String content;

  Article({
    required this.source,
    required this.author,
    required this.title,
    required this.description,
    required this.url,
    required this.urlToImage,
    required this.publishedAt,
    required this.content,
  });

  factory Article.fromJson(Map<String, dynamic> json) => Article(
    source: Source.fromJson(json["source"]),
    author: json["author"] ?? "Tidak ada author.",
    title: json["title"] ?? "Tidak ada title.",
    description: json["description"] ?? "Tidak ada description.",
    url: json["url"] ?? "Tidak ada url.",
    urlToImage: json["urlToImage"] ?? "https://thumbs.dreamstime.com/b/missing-image-vector-illustration-no-image-available-vector-concept-missing-image-vector-illustration-no-image-available-vector-121634529.jpg",
    publishedAt: DateTime.parse(json["publishedAt"] ?? "2023-11-20T02:19:48Z"),
    content: json["content"],
  );

  Map<String, dynamic> toJson() => {
    "source": source.toJson(),
    "author": author,
    "title": title,
    "description": description,
    "url": url,
    "urlToImage": urlToImage,
    "publishedAt": publishedAt.toIso8601String(),
    "content": content
  };
}

class Source {
  final String? id;
  final String name;

  Source({required this.id, required this.name});

  factory Source.fromJson(Map<String, dynamic> json) =>
      Source(id: json["id"], name: json["name"]);

  Map<String, dynamic> toJson() => {"id": id, "name": name};
}
