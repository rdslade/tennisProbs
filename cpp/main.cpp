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
void printBothPlayers(MatchPlayer &a, MatchPlayer &b){
  cout << "0 - " << a.getName() << std::endl;
  cout << "1 - " << b.getName() << std::endl;
  cout << "Enter the number corresponding to the first server: ";
}
void winSet(int player, Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  if(player == 0){
    a.winSet();
  }
  else if(player == 1){
    b.winSet();
  }
  m.resetSet();
}
void winGame(int player, Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  if(player == 0){
    a.winGame();
  }
  else if(player == 1){
    b.winGame();
  }
  m.resetGame();
}
void checkSetsInvariants(Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  int aGames = a.getGames();
  int bGames = b.getGames();
  if(aGames == 7 || (aGames == 6 && bGames <= 4)){
    winSet(0, m);
  }
  else if(bGames == 7 || (bGames == 6 && aGames <= 4)){
    winSet(1, m);
  }
}
void checkGameInvariants(Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  if(a.getPoints() >= 4 && b.getPoints() <= 2){
    winGame(0, m);
  }
  else if(b.getPoints() >= 4 && a.getPoints() <= 2){
    winGame(1, m);
  }
  else if(a.getPoints() == 5 && b.getPoints() == 3){
    winGame(0, m);
  }
  else if(b.getPoints() == 5 && a.getPoints() == 3){
    winGame(1, m);
  }
  else if(a.getPoints() == 4 && b.getPoints() == 4){
    m.setDuece();
  }
}
int checkMatchInvariants(Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  checkGameInvariants(m);
  checkSetsInvariants(m);
  if(a.getSets() == 2 || b.getSets() == 2){
    return 1;
  }
  else{
    return 0;
  }
}
int playPoint(Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  int winner;
  printBothPlayers(a,b);
  cout << "Enter the player who won the point: ";
  cin >> winner;
  if(winner == 0){
    a.winPoint();
  }
  else{
    b.winPoint();
  }
  return checkMatchInvariants(m);
}
void init_server(Match &m){
  MatchPlayer &a = m.getPlayer(0);
  MatchPlayer &b = m.getPlayer(1);
  printBothPlayers(a,b);
  int server;
  cin >> server;
  if(server != 0 && server != 1){
    throw InputException();
  }
  a.setServe(!server);
  b.setServe(server);
  m.setServerNetP();
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
  bool matchDone = false;
  while(!matchDone){
    cout << match << endl;
    matchDone = playPoint(match);
  }
  cout << match << endl << endl;
  MatchPlayer &aP = match.getPlayer(0);
  MatchPlayer &bP = match.getPlayer(1);
  MatchPlayer& winner = (aP.getSets() > bP.getSets()) ? aP : bP;
  MatchPlayer& loser = (aP.getSets() > bP.getSets()) ? bP : aP;
  cout << winner.getName() << " def. " << loser.getName() << " " << winner.getSets() << "-" << loser.getSets() << endl;
}
