#include <iostream>
#include <string>
#include "Match.h"

using namespace std;
class InputException{};
bool percent_invariant(double per){ return per >= 0 && per <= 1; }
void init_player(string &a_name, double &a_serve, double &a_ret){
     cout << "Enter a player's information" << std::endl;
     cout << "  Name: ";
     getline(cin, a_name);
     cout << "  Serve Point Percentage: ";
     string a_serve_str;
     getline(cin, a_serve_str);
     a_serve = stod(a_serve_str);
     if(!percent_invariant(a_serve)){
       throw InputException();
     }
     cout << "  Return Point Percentage: ";
     string a_ret_str;
     getline(cin, a_ret_str);
     a_ret = stod(a_ret_str);
     if(!percent_invariant(a_ret)){
       throw InputException();
     }
     cout << std::endl;
}
void init_server(Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  cout << "0 - " << a.getName() << std::endl;
  cout << "1 - " << b.getName() << std::endl;
  cout << "Enter the number corresponding to the first server: ";
  int server;
  cin >> server;
  if(server != 0 && server != 1){
    throw InputException();
  }
  a.setServe(!server);
  b.setServe(server);
  cout << std::endl;
}
int main(){
  string a_name, b_name;
  double a_serve, b_serve, a_ret, b_ret;
  bool error = true;
  while(error){
    try{
      init_player(a_name, a_serve, a_ret);
      init_player(b_name, b_serve, b_ret);
      error = false;
    }
    catch(const InputException &e){
      cout << std::endl << "Serve/Return point percentage must be between 0 and 1" << std::endl;
      cout << "Restarting input collection" << std::endl << std::endl;
    }
  }
  MatchPlayer a = MatchPlayer(a_name, a_serve, a_ret);
  MatchPlayer b = MatchPlayer(b_name, b_serve, b_ret);
  Match match(a, b);
  error = true;
  while(error){
    try{
      init_server(match);
      error = false;
    }
    catch(const InputException &e){
      cout << std::endl << "Enter either 0 or 1 to select server" << std::endl << std::endl;
    }
  }
  cout << match << endl;
}
