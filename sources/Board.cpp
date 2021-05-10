
#include "Board.hpp"
using namespace std;
using namespace pandemic;

Board::Board()
{
    gameMap = {
        {City::Algiers, cityData{City::Algiers}},
        {City::Atlanta, cityData{City::Atlanta}},
        {City::Baghdad, cityData{City::Baghdad}},
        {City::Bangkok, cityData{City::Bangkok}},
        {City::Beijing, cityData{City::Beijing}},
        {City::Bogota, cityData{City::Bogota}},
        {City::BuenosAires, cityData{City::BuenosAires}},
        {City::Cairo, cityData{City::Cairo}},
        {City::Chennai, cityData{City::Chennai}},
        {City::Chicago, cityData{City::Chicago}},
        {City::Delhi, cityData{City::Delhi}},
        {City::Essen, cityData{City::Essen}},
        {City::HoChiMinhCity, cityData{City::HoChiMinhCity}},
        {City::HongKong, cityData{City::HongKong}},
        {City::Istanbul, cityData{City::Istanbul}},
        {City::Jakarta, cityData{City::Jakarta}},
        {City::Johannesburg, cityData{City::Johannesburg}},
        {City::Karachi, cityData{City::Karachi}},
        {City::Khartoum, cityData{City::Khartoum}},
        {City::Kinshasa, cityData{City::Kinshasa}},
        {City::Kolkata, cityData{City::Kolkata}},
        {City::Lagos, cityData{City::Lagos}},
        {City::Lima, cityData{City::Lima}},
        {City::London, cityData{City::London}},
        {City::LosAngeles, cityData{City::LosAngeles}},
        {City::Madrid, cityData{City::Madrid}},
        {City::Manila, cityData{City::Manila}},
        {City::MexicoCity, cityData{City::MexicoCity}},
        {City::Miami, cityData{City::Miami}},
        {City::Milan, cityData{City::Milan}},
        {City::Montreal, cityData{City::Montreal}},
        {City::Moscow, cityData{City::Moscow}},
        {City::Mumbai, cityData{City::Mumbai}},
        {City::NewYork, cityData{City::NewYork}},
        {City::Osaka, cityData{City::Osaka}},
        {City::Paris, cityData{City::Paris}},
        {City::Riyadh, cityData{
                           City::Riyadh,
                       }},
        {City::SanFrancisco, cityData{City::SanFrancisco}},
        {City::Santiago, cityData{City::Santiago}},
        {City::SaoPaulo, cityData{City::SaoPaulo}},
        {City::Seoul, cityData{City::Seoul}},
        {City::Shanghai, cityData{City::Shanghai}},
        {City::StPetersburg, cityData{City::StPetersburg}},
        {City::Sydney, cityData{City::Sydney}},
        {City::Taipei, cityData{City::Taipei}},
        {City::Tehran, cityData{City::Tehran}},
        {City::Tokyo, cityData{City::Tokyo}},
        {City::Washington, cityData{City::Washington}}};
}

int &Board::operator[](City city)
{
    return Board::gameMap[city].cubes;
}

bool Board::is_clean()
{
    for (auto &&i : this->gameMap)
    {
        if (i.second.cubes!=0)
        {
            return false;
        }
        
    }
    return true;
    
}

ostream &pandemic::operator<<(ostream &out, const Board &b)
{
    out << "----------------------------------------\n";
    out << "         Level of the disease\n";
    out << "----------------------------------------\n";
   
    for (auto &&i : b.gameMap)
    {
        out<<"City: "<<i.second.name<<" Level: "<<i.second.cubes<<endl;
    }

    out << "----------------------------------------\n";
    out << "              Medicines\n";
    out << "----------------------------------------\n";
    for (auto &&i : b.medicine)
    {
        if(i.second){
            out<<"Medicines for the illness: "<<Colors_to_string[i.first]<<endl;
        }
        
    }
    out << "----------------------------------------\n";
    out << "           Research stations\n";
    out << "----------------------------------------\n";

      for (auto &&i : b.gameMap)
    {
       if(i.second.research_station){
           out<<i.second.name<<" station.\n";
       }
    }
    return out;
}
cityData Board::get_cityData(City city)
{
    return Board::gameMap[city];
}
void Board::remove_cures(){
    for (auto &&i : this->medicine)
    {
        medicine[i.first]=false;
    }
    
}
void Board::remove_stations(){
    for (auto &&i : this->gameMap)
    {
        this->gameMap[i.first].research_station=false;
        
    }
    
}
