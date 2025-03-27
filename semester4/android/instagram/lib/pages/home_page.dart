import 'package:flutter/material.dart';
import 'package:instagram/components/post_widget.dart';

final List<Map<String, String>> _stories = [
  {
    'username': 'Your story',
    'image': 'assets/images/image.png',
  },
  {
    'username': 'AdrianT',
    'image': 'assets/images/image.png',
  },
  {
    'username': 'JohnDoe',
    'image': 'assets/images/image.png',
  },
  {
    'username': 'JaneDoe',
    'image': 'assets/images/image.png',
  },
  {
    'username': 'FlutterDev',
    'image': 'assets/images/image.png',
  },
  {
    'username': 'DartLang',
    'image': 'assets/images/image.png',
  },
];

final List<Map<String, String>> _posts = [
  {
    'username': 'AdrianT',
    'location': 'Tokyo, Japan',
    'avatar': 'assets/images/image.png',
    'image': 'assets/images/image.png',
    'likes': '44,686',
    'caption': 'AdrianT lagi ideasi buat aplikasi pdbI. inshallah tahun depan IPO IHSG...'
  },
  {
    'username': 'DummyUser',
    'location': 'Jakarta, Indonesia',
    'avatar': 'assets/images/image.png',
    'image': 'assets/images/image.png',
    'likes': '12,345',
    'caption': 'Some interesting caption here...'
  },
  {
    'username': 'AnotherOne',
    'location': 'Seoul, South Korea',
    'avatar': 'assets/images/image.png',
    'image': 'assets/images/image.png',
    'likes': '9,999',
    'caption': 'Exploring new ideas with Flutter.'
  },
];

class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  PreferredSizeWidget _buildInstagramAppBar() {
    return AppBar(
      backgroundColor: Colors.white,
      elevation: 0,
      leading: IconButton(
        icon: Icon(Icons.camera_alt_outlined, color: Colors.black),
        onPressed: () {},
      ),
      title: Image.asset(
        'assets/images/logo.png',
        height: 40,
      ),
      centerTitle: true,
      actions: [
        IconButton(
          icon: Icon(Icons.live_tv_outlined, color: Colors.black),
          onPressed: () {},
        ),
        IconButton(
          icon: Icon(Icons.send, color: Colors.black),
          onPressed: () {},
        ),
      ],
    );
  }

  Widget _buildStoriesSection() {
    return Container(
      height: 110,
      child: ListView.separated(
        scrollDirection: Axis.horizontal,
        itemCount: _stories.length,
        separatorBuilder: (_, __) => SizedBox(width: 8),
        padding: EdgeInsets.symmetric(horizontal: 8, vertical: 8),
        itemBuilder: (context, index) {
          final story = _stories[index];
          return Column(
            children: [
              CircleAvatar(
                radius: 32,
                backgroundImage: AssetImage(story['image']!),
              ),
              SizedBox(height: 5),
              SizedBox(
                width: 64,
                child: Text(
                  story['username']!,
                  textAlign: TextAlign.center,
                  overflow: TextOverflow.ellipsis,
                  style: TextStyle(fontSize: 12),
                ),
              ),
            ],
          );
        },
      ),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: _buildInstagramAppBar(),
      backgroundColor: Colors.white,
      body: ListView(
        children: [
          _buildStoriesSection(),

          Divider(thickness: 1, color: Colors.grey[300]),

          for (var post in _posts) PostWidget(post: post),
        ],
      ),
    );
  }
}
