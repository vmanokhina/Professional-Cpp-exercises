#pragma once
#include <string>
#include <optional>

// левый const: никто снаружи не может поменять значение которое возвращает функция
// левый const нужен ТОЛЬКО тогда, когда ты возвращаешь ССЫЛКУ (&) или УКАЗАТЕЛЬ (*)

// правый const: функция не меняет переменные внутри класса

// ПРАВЫЕ const везде, где функция не меняет данные private. А левый const добавляй только тогда, когда видишь амперсанд & на возврате!

class AirlineTicket
{
public:
    AirlineTicket() = default;
    ~AirlineTicket() = default;
    double calculatePriceInDollars() const;

    const std::string& getPassengerName() const; 
    void setPassengerName(const std::string& name);

    int getNumberOfMiles() const;
    void setNumberOfMiles(int miles);

    bool hasEliteSuperRewardsStatus() const;
    void setHasEliteSuperRewardsStatus(bool status);

    std::optional<int> getFrequentFlyerNumber() const;
    void setFrequentFlyerNumber(std::optional<int> number); // мы сможем передавать туда либо число, либо специальное слово std::nullopt 
                                            // (что означает "пустота", "сбросить значение")

private:
    std::string m_passengerName;
    int m_numberOfMiles;
    bool m_hasEliteSuperRewardsStatus;
    std::optional<int> m_frequentFlyerNumber;
};