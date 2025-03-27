import 'dart:async';
import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'package:geocoding/geocoding.dart';
import 'package:geolocator/geolocator.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';

import '../map_type_google.dart';

class MapsV2Page extends StatefulWidget {
  const MapsV2Page({super.key});

  @override
  State<MapsV2Page> createState() => _MapsV2PageState();
}

class _MapsV2PageState extends State<MapsV2Page> {
  final Completer<GoogleMapController> _controller =
      Completer<GoogleMapController>();
  double latitude = -7.2804494;
  double longitude = 112.7947228;
  var mapType = MapType.normal;
  Position? devicePosition;
  String address = "";

  @override
  void initState() {
    super.initState();
    _checkPermissionAndGetLocation();
  }

  Future<void> _checkPermissionAndGetLocation() async {
    LocationPermission permission = await Geolocator.checkPermission();
    if (permission == LocationPermission.denied) {
      permission = await Geolocator.requestPermission();
      if (permission == LocationPermission.denied) {
        Fluttertoast.showToast(msg: "Location permissions are denied");
        return;
      }
    }

    if (permission == LocationPermission.deniedForever) {
      Fluttertoast.showToast(
        msg:
            "Location permissions are permanently denied, please enable in settings",
      );
      return;
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Google Maps V2"),
        actions: [
          PopupMenuButton(
            onSelected: onSelectedMapType,
            itemBuilder: (context) {
              return googleMapTypes.map((typeGoogle) {
                return PopupMenuItem(
                  value: typeGoogle.type,
                  child: Text(typeGoogle.type.name),
                );
              }).toList();
            },
          ),
        ],
      ),
      body: Stack(children: [_buildGoogleMaps(), _buildSearchCard()]),
    );
  }

  Widget _buildGoogleMaps() {
    return GoogleMap(
      mapType: mapType,
      initialCameraPosition: CameraPosition(
        target: LatLng(latitude, longitude),
        zoom: 14,
      ),
      onMapCreated: (GoogleMapController controller) {
        _controller.complete(controller);
      },
      myLocationEnabled: true,
      myLocationButtonEnabled: false,
    );
  }

  Widget _buildSearchCard() {
    return Padding(
      padding: const EdgeInsets.all(16),
      child: SizedBox(
        height: 150,
        width: double.infinity,
        child: Material(
          elevation: 8,
          borderRadius: BorderRadius.circular(10),
          child: Column(
            children: [
              // field pencarian
              Padding(
                padding: const EdgeInsets.only(
                  left: 20,
                  right: 20,
                  top: 8,
                  bottom: 4,
                ),
                child: TextField(
                  decoration: InputDecoration(
                    hintText: 'Masukkan alamat...',
                    contentPadding: const EdgeInsets.only(left: 15, top: 15),
                    suffixIcon: IconButton(
                      onPressed: searchLocation,
                      icon: const Icon(Icons.search),
                    ),
                  ),
                  onChanged: (value) {
                    address = value;
                  },
                  onSubmitted: (value) {
                    searchLocation();
                  },
                ),
              ),
              // tombol untuk mendapatkan posisi device
              ElevatedButton(
                onPressed: () async {
                  Position? value = await getCurrentPosition();
                  if (value != null) {
                    setState(() {
                      devicePosition = value;
                      // Update the main coordinates too
                      latitude = value.latitude;
                      longitude = value.longitude;
                    });

                    GoogleMapController controller = await _controller.future;
                    final cameraPosition = CameraPosition(
                      target: LatLng(value.latitude, value.longitude),
                      zoom: 17,
                    );
                    final cameraUpdate = CameraUpdate.newCameraPosition(
                      cameraPosition,
                    );
                    controller.animateCamera(cameraUpdate);
                  }
                },
                child: const Text("Dapatkan lokasi saat ini"),
              ),
              // teks latitude dan longitude
              devicePosition != null
                  ? Text(
                    "Lokasi saat ini : ${devicePosition?.latitude.toStringAsFixed(6)} ${devicePosition?.longitude.toStringAsFixed(6)}",
                  )
                  : const Text("Lokasi belum terdeteksi"),
            ],
          ),
        ),
      ),
    );
  }

  Future<Position?> getCurrentPosition() async {
    Position? currentPosition;
    try {
      currentPosition = await Geolocator.getCurrentPosition(
        desiredAccuracy: LocationAccuracy.best,
      );
    } catch (e) {
      Fluttertoast.showToast(msg: "Error getting location: ${e.toString()}");
      currentPosition = null;
    }
    return currentPosition;
  }

  Future<void> searchLocation() async {
    if (address.isEmpty) {
      Fluttertoast.showToast(msg: "Please enter an address");
      return;
    }

    try {
      List<Location>? locations = await GeocodingPlatform.instance
          ?.locationFromAddress(address);

      if (locations!.isNotEmpty) {
        GoogleMapController controller = await _controller.future;
        LatLng target = LatLng(locations[0].latitude, locations[0].longitude);
        CameraPosition cameraPosition = CameraPosition(
          target: target,
          zoom: 17,
        );
        CameraUpdate cameraUpdate = CameraUpdate.newCameraPosition(
          cameraPosition,
        );
        controller.animateCamera(cameraUpdate);
      } else {
        Fluttertoast.showToast(msg: "No locations found for this address");
      }
    } catch (e) {
      Fluttertoast.showToast(msg: "Alamat tidak ditemukan: ${e.toString()}");
    }
  }

  void onSelectedMapType(Type value) {
    setState(() {
      switch (value) {
        case Type.Normal:
          mapType = MapType.normal;
          break;
        case Type.Hybrid:
          mapType = MapType.hybrid;
          break;
        case Type.Terrain:
          mapType = MapType.terrain;
          break;
        case Type.Satellite:
          mapType = MapType.satellite;
          break;
      }
    });
  }
}
