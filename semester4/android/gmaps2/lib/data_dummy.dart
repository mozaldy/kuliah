import 'package:google_maps_flutter/google_maps_flutter.dart';

Set<Marker> markers = {
  Marker(
      markerId: const MarkerId("Politeknik Elektronika Negeri Surabaya"),
      position: const LatLng(-7.2758471, 112.7937557),
      infoWindow: const InfoWindow(title: "Perguruan Tinggi Vokasi"),
      icon: BitmapDescriptor.defaultMarkerWithHue(BitmapDescriptor.hueRed)),
  Marker(
      markerId: const MarkerId("Institut Teknologi Sepuluh Nopember"),
      position: const LatLng(-7.282356, 112.7949253),
      infoWindow: const InfoWindow(title: "Perguruan Tinggi Negeri"),
      icon: BitmapDescriptor.defaultMarkerWithHue(BitmapDescriptor.hueRed)),
  Marker(
      markerId: const MarkerId("Galaxy Mall 3"),
      position: const LatLng(-7.2756967, 112.7806254),
      infoWindow: const InfoWindow(title: "Mall Surabaya Barat"),
      icon: BitmapDescriptor.defaultMarkerWithHue(BitmapDescriptor.hueRed)),
  Marker(
      markerId: const MarkerId("Convention Hall Arief Rahman Hakim"),
      position: const LatLng(-7.2886493, 112.7836333),
      infoWindow: const InfoWindow(title: "Convention Hall"),
      icon: BitmapDescriptor.defaultMarkerWithHue(BitmapDescriptor.hueRed)),
  Marker(
      markerId: const MarkerId("Pakuwon City Mall"),
      position: const LatLng(-7.2768784, 112.8061882),
      infoWindow: const InfoWindow(title: "Pakuwon City"),
      icon: BitmapDescriptor.defaultMarkerWithHue(BitmapDescriptor.hueRed))
};