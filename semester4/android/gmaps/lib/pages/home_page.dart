import 'package:flutter/material.dart';

class HomePage extends StatelessWidget{
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    // TODO: implement build
    return Scaffold(
      appBar: AppBar(
        title: const Text('HIDUP JOKOWE'),
      ),
      body: Stack(
        children: <Widget>[
          SafeArea(child: Container(
            child: Text("HIDUP JOKOWE"),
          )), SafeArea(child: Container(
            child: Column(children: <Widget>[
              Semantics(
                label: 'Google Maps Logo',
                child: Image.network('https://upload.wikimedia.org/wikipedia/commons/thumb/a/aa/Google_Maps_icon_%282020%29.svg/1428px-Google_Maps_icon_%282020%29.svg.png'),
              ),
            ],),
          ))
        ],
      )
    );
  }
}