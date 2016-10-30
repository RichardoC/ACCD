//
// Created by Richard Finlay Tweed on 30/10/2016.
//

#include <sstream>
#include <time.h>
#include "CellUser.h"

CellUser::CellUser() {

}

CellUser::CellUser(std::string line) {
    std::istringstream iss(line);
    iss >> m_timestamp;
    int milliTimeStamp = m_timestamp/1000;
    std::time_t m_dateTime = static_cast<time_t>(milliTimeStamp);

    iss >> m_lat;
    iss >> m_lng;
    iss >> m_signal_inst;
    iss >> m_signal_min;
    iss >> m_signal_max;
    iss >> m_signal_average;
    iss >> m_carrier;
    iss >> m_full_carrier;
    iss >> m_status;
    iss >> m_net;
    iss >> m_net_type;
    iss >> m_lac;
    iss >> m_cid;
    iss >> m_psc;
    iss >> m_speed;
    iss >> m_satellites;
    iss >> m_precision1;
    iss >> m_provider;
    iss >> m_activity;




}
