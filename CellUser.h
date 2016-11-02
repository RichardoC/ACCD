//
// Created by Richard Finlay Tweed on 30/10/2016.
//

#ifndef ACCD_CELLUSER_H
#define ACCD_CELLUSER_H


#include <string>

class CellUser {
public:
    CellUser();
    CellUser(std::string line);




private:
    long m_timestamp;
    std::time_t m_dateTime;
    std::string m_dateTimeS;
    float m_lat;
    float m_lng;
    int m_signal_inst;
    int m_signal_min;
    int m_signal_max;
    int m_signal_average;
    std::string m_carrier;
    std::string m_full_carrier;
    int m_status;
    int m_net;
    std::string m_net_type;
    int m_lac;
    long m_cid;
    int m_psc;
    float m_speed;
    int m_satellites;
    int m_precision1;
    std::string m_provider;
    int m_activity;
//    std::string m_incident;


};


#endif //ACCD_CELLUSER_H
