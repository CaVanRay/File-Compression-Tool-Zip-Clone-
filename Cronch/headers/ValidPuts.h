#pragma once
#include <string>

// Functions to validate inputs & index

//******************************************************************

std::string getStringP(const std::string& prompt);

std::string getString();

std::string getStringS();

//******************************************************************

int getIntP(const std::string& prompt);

int getInt();

int getIntS();

//******************************************************************

double getDoubleP(const std::string& prompt);

double getDouble();

double getDoubleS();

//******************************************************************

bool getYN(const std::string& prompt);

bool getYN();

//******************************************************************

bool isValidVin(car*& head, const std::string& vin);

//******************************************************************

std::string getVIN(const std::string& prompt, car*& head);

//******************************************************************

