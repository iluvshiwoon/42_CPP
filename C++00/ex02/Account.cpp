#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


void Account::_displayTimestamp(void) {
    std::time_t now = std::time(0);           // Get current time
    std::tm* timeinfo = std::localtime(&now); // Convert to local time
    
    std::cout << "[" 
              << (timeinfo->tm_year + 1900)   // Year (tm_year is years since 1900)
              << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)  // Month (0-11, so +1)
              << std::setfill('0') << std::setw(2) << timeinfo->tm_mday       // Day
              << "_"
              << std::setfill('0') << std::setw(2) << timeinfo->tm_hour       // Hour
              << std::setfill('0') << std::setw(2) << timeinfo->tm_min        // Minutes
              << std::setfill('0') << std::setw(2) << timeinfo->tm_sec        // Seconds
              << "] ";
}

Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _nbAccounts += 1;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(){
    return _nbAccounts;
}

int Account::getTotalAmount(){
    return _totalAmount;
}

int Account::getNbDeposits(){
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout << "account:" << _nbAccounts << ";amount:" << _totalAmount << ";deposits:"\
        << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit \
        << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
    _amount += deposit; 
    _nbDeposits += 1;
    _totalAmount += deposit;
    _totalNbDeposits += 1;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (_amount >= withdrawal)
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals += 1;
        _totalNbWithdrawals += 1;
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal \
        << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" \
        << _nbWithdrawals << std::endl;

        return true;
    }
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount \
        << ";withdrawal:" << "refused" << std::endl;
    return false;
}

int Account::checkAmount() const{
    return _amount;
}

void Account::displayStatus() const{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits \
        << ";withdrawals:" << _nbWithdrawals << std::endl;
}
