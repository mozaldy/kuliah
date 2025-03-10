class Book {
  String name;
  String image;
  String description;
  double rate;
  int page;
  String categoryBook;
  String language;

  Book({
    required this.name,
    required this.image,
    required this.description,
    required this.rate,
    required this.page,
    required this.categoryBook,
    required this.language,
    
  });
}

List<Book> listBook = [
  Book(name: "Agile", image: "assets/images/agile.jpg", description: "Buku agile aseeek", rate: 10, page: 100, categoryBook: "Fiction", language: "English"),
  Book(name: "Agile 2", image: "assets/images/agile.jpg", description: "Buku agile aseeek", rate: 10, page: 100, categoryBook: "Fiction", language: "English"),
  Book(name: "Agile 3", image: "assets/images/agile.jpg", description: "Buku agile aseeek", rate: 10, page: 100, categoryBook: "Fiction", language: "English"),
  Book(name: "Agile 4", image: "assets/images/agile.jpg", description: "Buku agile aseeek", rate: 10, page: 100, categoryBook: "Fiction", language: "English"),
  Book(name: "Agile 5", image: "assets/images/agile.jpg", description: "Buku agile aseeek", rate: 10, page: 100, categoryBook: "Fiction", language: "English"),
];