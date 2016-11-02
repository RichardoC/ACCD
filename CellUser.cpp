//
// Created by Richard Finlay Tweed on 30/10/2016.
//

#include <sstream>
#include <time.h>
#include "CellUser.h"

CellUser::CellUser() {

}

//importing each cell user from a line of input
CellUser::CellUser(std::string line) {
    std::istringstream iss(line);

    std::string temp;
    getline(iss, temp,',');
    m_timestamp = atol(temp.c_str());

    long milliTimeStamp = m_timestamp/1000;
    std::time_t m_dateTime = static_cast<time_t>(milliTimeStamp);


    getline(iss, m_dateTimeS,',');
    //stripping the "
    m_dateTimeS.erase(0,1);
    m_dateTimeS.erase(m_dateTimeS.size()-1,1);



    getline(iss, temp,',');
    m_lat = std::stof(temp.c_str());

    getline(iss, temp,',');
    m_lng = std::stof(temp.c_str());

    getline(iss, temp,',');
    m_signal_inst = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_signal_min = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_signal_max = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_signal_average = std::atoi(temp.c_str());

    getline(iss, m_carrier,',');
    if(m_carrier.at(0)=='\"'){
        m_carrier.erase(0,1);
        m_carrier.erase(m_carrier.size()-1,1);
    }

    getline(iss, m_full_carrier,',');
    if(m_full_carrier.at(0)=='\"'){
        m_full_carrier.erase(0,1);
        m_full_carrier.erase(m_full_carrier.size()-1,1);
    }

    getline(iss, temp,',');
    m_status = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_net = std::atoi(temp.c_str());

    getline(iss, m_net_type,',');

    getline(iss, temp,',');
    m_lac = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_cid = atol(temp.c_str());

    getline(iss, temp,',');
    m_psc = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_speed = std::stof(temp.c_str());

    getline(iss, temp,',');
    m_satellites = std::atoi(temp.c_str());

    getline(iss, temp,',');
    m_precision1 = std::atoi(temp.c_str());

    getline(iss, m_provider,',');

    getline(iss, temp,',');
    m_activity = std::atoi(temp.c_str());

}
