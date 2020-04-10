//
// Created by Пенёк on 03/11/2019.
//

#include "integration.h"
#include "statlist.h"
#include <cstdlib>
#include <iostream>

void _stat_to_char(CStat &stat, char * &res){
    json j;
    stat.to_json(j);
    std::string str = j.dump();
    res = (char*) malloc(sizeof(char) * (str.size() + 1));
    for (int i = 0; i < str.size(); ++i){
        res[i] = str[i];
    }
    res[str.size()] = '\0';
}

int read_stat_(char * name, char * &res){
    CStat stat;
    stat.init(name);
    if (!stat.isinitialized)
        return 1;
    _stat_to_char(stat, res);
    return 0;
}

int stat_intersect_(char * st1, char * st2, char * &res1, char * &res2){
    std::cout << "Going to parse\n\n";
    json j1 = json::parse(st1), j2 = json::parse(st2);
    std::cout << "Parse OK\n\n";
    CStat stat1(j1), stat2(j2), stat_res1, stat_res2;
    std::cout << "Going to intersect\n\n";
    stat_intersect(stat1, stat2, stat_res1, stat_res2);
    std::cout << "Intersect OK\n\n";
    if (!stat1.isinitialized || !stat2.isinitialized || !stat_res1.isinitialized || !stat_res2.isinitialized){
        std::cout << ">>  Not inicialized\n\n";
        return 1;
    }
    _stat_to_char(stat_res1, res1);
    _stat_to_char(stat_res2, res2);
    return 0;
}