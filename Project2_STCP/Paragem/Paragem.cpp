//
// Created by Vasco Enes on 27/01/2022.
//

#include "Paragem.h"

const string &Paragem::getCode() const {
    return code;
}

void Paragem::setCode(const string &code) {
    Paragem::code = code;
}

const string &Paragem::getName() const {
    return name;
}

void Paragem::setName(const string &name) {
    Paragem::name = name;
}

double Paragem::getLatitude() const {
    return latitude;
}

void Paragem::setLatitude(double latitude) {
    Paragem::latitude = latitude;
}

double Paragem::getLongitude() const {
    return longitude;
}

void Paragem::setLongitude(double longitude) {
    Paragem::longitude = longitude;
}

const string &Paragem::getZone() const {
    return zone;
}

void Paragem::setZone(const string &zone) {
    Paragem::zone = zone;
}

Paragem::Paragem() {
    code = "";
    name = "";
    zone = "";
    latitude = 0.0;
    longitude = 0.0;
}

Paragem::Paragem(string code, string name, string zone, double lat, double longi) {
    this->code = code;
    this->name = name;
    this->zone = zone;
    this->latitude = lat;
    this->longitude = longi;
}

ostream &operator<<(ostream &os, const Paragem &paragem) {
    os << "code: " << paragem.code << " name: " << paragem.name << " zone: " << paragem.zone << " latitude: "
       << paragem.latitude << " longitude: " << paragem.longitude << endl;
    return os;
}

bool Paragem::operator<(const Paragem &rhs) const {
    return code < rhs.code;
}

bool Paragem::operator==(const Paragem &rhs) const {
    if (code == rhs.code && name == rhs.name && zone == rhs.zone){
        return true;
    }
    return false;
}

double Paragem::distanciaEntreParagens(const Paragem& src, const Paragem& dest) {

    // distance between latitudes
    // and longitudes
    double lat1, lat2, lon1, lon2;

    lat1 = src.latitude;
    lat2 = dest.latitude;
    lon1 = src.longitude;
    lon2 = dest.longitude;

    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}






