//
// Created by Vasco Enes on 27/01/2022.
//

#ifndef UNTITLED_PARAGEM_H
#define UNTITLED_PARAGEM_H

#include <string>
#include <ostream>
#include <cmath>

using namespace std;

class Paragem {

private:

    string code;
    string name;
    string zone;
    double latitude;
    double longitude;

public:
    /**
     * \brief Constructor of the class
     */
    Paragem();
    /**
     * \brief Constructor of the class
     * @param code code of the stop
     * @param name name of the stop
     * @param zone zone of the stop
     * @param lat latitude of the stop
     * @param longi longitude of the stop
     */
    Paragem(string code, string name, string zone, double lat, double longi);
    /**
     * \brief getter of the code
     * @return code
     */
    const string &getCode() const;
    /**
     * \brief setter of the code
     * @param code new code of the stop
     */
    void setCode(const string &code);
    /**
     * \brief getter of the name
     * @return the name of the stop
     */
    const string &getName() const;
    /**
     * \brief setter of the name
     * @param name new name of the stop
     */
    void setName(const string &name);
    /**
     * \brief getter of the latitude
     * @return latitude
     */
    double getLatitude() const;
    /**
     * \brief setter of the latitude
     * @param latitude new latitude of the stop
     */
    void setLatitude(double latitude);
    /**
     * \brief getter of the longitude
     * @return longitude of the stop
     */
    double getLongitude() const;
    /**
     * \brief setter of the longitude
     * @param longitude longitude of the stop
     */
    void setLongitude(double longitude);
    /**
     * \brief getter of the zone
     * @return zone of the stop
     */
    const string &getZone() const;
    /**
     * \brief setter of the zone
     * @param zone new zone of the stop
     */
    void setZone(const string &zone);

    /**
     * \brief operator to show te outuput of the object
     * @param os ostream
     * @param paragem stop to show
     * @return ostream
     */
    friend ostream &operator<<(ostream &os, const Paragem &paragem);

    /**
     * \brief smaller than operator
     * @param rhs stop to compare
     * @return true if smaller, false if not
     */
    bool operator<(const Paragem &rhs) const;

    /**
     * \brief equal operator
     * @param rhs stop to compare
     * @return true if equal, false if not
     */
    bool operator==(const Paragem &rhs) const;

    /**
     * \brief computes the distance between two stops
     * @param src source stop
     * @param dest destination stop
     * @return distance between the two stops in kms
     */
    double static distanciaEntreParagens(const Paragem& src, const Paragem& dest);

};



#endif //UNTITLED_PARAGEM_H
