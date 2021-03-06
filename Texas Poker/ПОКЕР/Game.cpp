#include<iostream>
#include<time.h>
#include<string>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <exception>
#include <Windows.h>
#include <stdio.h>
using namespace std;

const int RANKS[13] = { 2,3,4,5,6,7,8,9,10,11,12,13,14 };
const char SUITS[4] = { 3,4,5,6 };

//===========================================================================================================
class Deck_of_cards
{
	pair<int, char>tmp;
	vector < pair<int, char>>Deck;
	int size;
public:
    
	Deck_of_cards() { size = 0; }
	int get_size()  { return size; }
	
	void _Deck()
	{  
		for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 13; j++)
				{
					tmp.first = RANKS[j];
					tmp.second = SUITS[i];
					Deck.push_back(tmp);
					size++;
				}
			  }
       }
 int Find_card_first(int index)
  {
	  if (index < Deck.size())
		  return Deck[index].first; 
	
  }
 char Find_card_second(int index)
 {
	 if (index < Deck.size())
		 return Deck[index].second;

 }
 void Delete_card(int index)
 {
	 if (index < Deck.size())
		 Deck.erase(Deck.begin() + index);
	 size--;
 }

  void Show()
  {
	  for (int i = 0; i <size; i++)
	  {
		  if (0 == (i % 13))
		  {
			  cout << "\n\n";
		  }
		  if (Deck[i].first > 10)
		  {
			  if (Deck[i].first == 11)cout << i + 1 << ")=J" << Deck[i].second << setw(5);
			  if (Deck[i].first == 12)cout << i + 1 << ")=Q" << Deck[i].second << setw(5);
			  if (Deck[i].first == 13)cout << i + 1 << ")=K" << Deck[i].second << setw(5);
			  if (Deck[i].first == 14)cout << i + 1 << ")=A" << Deck[i].second << setw(5);
		  }
		  else
	           cout << i + 1 << ")="<< Deck[i].first << Deck[i].second << setw(5);
		}
  }

 
};
//========================================================================================================

class Bet
{   
	int bet;
public:
	Bet() { bet = 20; }
	Bet(int _bet) { bet=_bet; }
	void set_bet(int _bet)
	{  
		bet =_bet;
	}
	int get_bet() { return bet; }
	void raise_bet(int _bet)
	{
		int sum = get_bet() + _bet;
		set_bet(sum);
	}
	void Show_bet() { cout << " Money is " << bet << "\n"; }


};
//========================================================================================================
class Player
{
	pair<int, char>tmp1;
	vector<pair<int, char >> player;
	int size;
	Bet obj;

public:
	Player() { size = 0; }
	Player(int _bet) : obj(_bet) {};
	int get_size() { return size; }
	int find_card_first(int index)
	{
	    if (index < player.size())
			return player[index].first;
	}
	char find_card_second(int index)
	{
	    if (index < player.size())
			return player[index].second;

	}
	void Give_card_to_player(Deck_of_cards &Deck)
		{
			int index = 1 + rand() % Deck.get_size() - 1;
			
			for (int i = 0; i <Deck.get_size(); i++)
			{
				tmp1.first = Deck.Find_card_first(index);
				tmp1.second= Deck.Find_card_second(index);
				break;
			}

			Deck.Delete_card(index);
			
		 player.push_back(tmp1);
		 size++;
			
		}
	void Diler_card_to_player(Player &tmp)
	{
		for (int i = 0; i <tmp.get_size(); i++)
		{
			tmp1.first = tmp.find_card_first(i);
			tmp1.second = tmp.find_card_second(i);
			player.push_back(tmp1);
			size++;
		}
  }
//=========================================================================================================
	void SetPositionCard(int x, int y)
	{
        
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD Position;
		Position.X = x;
		Position.Y = y;
	    SetConsoleCursorPosition(hConsole,Position);
	}
	void SetCardColour()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	}
//----------------------------------------------------------------------------------------------------------	
	void Show_cards()
	{
	
		sort(player.begin(), player.end());
		
		
		for (int i = 0; i < player.size(); i++)
		{
			if (player[i].first > 10)
				{
					if (player[i].first == 11) { cout << setw(2) << i + 1 << ")= J" << player[i].second << "\n"; }
					if (player[i].first == 12) { cout << setw(2) << i + 1 << ")= Q" << player[i].second << "\n"; }
					if (player[i].first == 13) { cout << setw(2) << i + 1 << ")= K" << player[i].second << "\n"; }
					if (player[i].first == 14) { cout << setw(2) << i + 1 << ")= A" << player[i].second << "\n"; }
				}

				else
				{
					cout << i + 1 << ") = " << player[i].first << player[i].second << "\n ";
				}
			}
		
	}
	void Show_one_card()
	{
		
		sort(player.begin(), player.end());
       for (int i = 0; i <player.size(); i++)
		{
			if (player[i].first > 10)
			{
				if (player[i].first == 11)
				{ 
				cout << "============\n";
				cout << "|J"<< player[i].second <<setw(10)<<"|\n";
				cout << "|"<<setw(12)<<"|\n";
				cout << "|"<<setw(12)<<"|\n";
				cout << "|"<<setw(6)<<player[i].second <<setw(6)<<"|\n";
				cout << "|"<<setw(12)<<"|\n";
				cout << "|"<<setw(12)<<"|\n";
				cout << "|"<<setw(9)<<"J"<< player[i].second <<"|\n";
				cout << "============\n";
				}
				if (player[i].first == 12)
				{ 
					cout << "============\n";
					cout << "|Q" << player[i].second << setw(10) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(9) << "Q" << player[i].second << "|\n";
					cout << "============\n";
				}
				if (player[i].first == 13) 
				{
					cout << "============\n";
					cout << "|K" << player[i].second << setw(10) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(9) << "K" << player[i].second << "|\n";
					cout << "============\n";
				}
				if (player[i].first == 14) 
				{ 
					cout << "============\n";
					cout << "|A" << player[i].second << setw(10) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(12) << "|\n";
					cout << "|" << setw(9) << "A" << player[i].second << "|\n";
					cout << "============\n";
				}
			}
			
			else
			{
				cout << "============\n";
				cout << "|"<< player[i].first << player[i].second << setw(10) <<"|\n";
				cout << "|"<< setw(12) <<"|\n";
				cout << "|"<< setw(12) <<"|\n";
				cout << "|"<< setw(6) << player[i].second << setw(6) <<"|\n";
				cout << "|"<< setw(12) <<"|\n";
				cout << "|"<< setw(12) <<"|\n";
				cout << "|"<< setw(9) << player[i].first << player[i].second <<"|\n";
				cout << "============\n";
			}
            }

	}
//--------------------------------------------------------------------------------------------------------------
	void set_Bet(int money)
	{
		obj.set_bet(money);
	}
	int get_Bet()
	{
		return obj.get_bet();
	}
	void Raise_bet(int _bet)
	{
	  obj.raise_bet(_bet);
	}
	void show_Bet()
	{
		obj.Show_bet();
	}
//------------------------------------------------------------------------------------------------------------
	
	void Start_hand(Deck_of_cards &Deck)//������, ������� �� ��� ����� + ������ � �����
	{
		for (int i = 0; i < 2; i++)
		{
			Give_card_to_player(Deck);
		}

    }
	void Flop(Deck_of_cards &Deck)//��� ����� �������� �����
	{
		for (int i = 0; i < 3; i++)
		{
			Give_card_to_player(Deck);
		}
	}
//=======================================================================================================================
	bool One_Pair()//���� ����
	{
		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i+1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first)
				{
					return true;
				}
	         }
		}
		return false;
	}
//--------------------------------------------------------------------------------------------------------------------------
	int _One_Pair()//���� ����
	{
		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i + 1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first)
				{
					return player[i].first;
				}
			}
		}
	}
//=======================================================================================================================	
	bool Two_Pair()//��� ����
	{
		int pair1 = 0;
		int pair2 = 0;
		int pos = 0;

		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i + 1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first && !pair1) { pair1 = 1; pos = i + 2; }
				else if (pair1 == 1)
					i = 6;
			}
		}
				if (pair1 == 1 && pos < player.size())
					{
					  for (int i = pos; i < player.size(); ++i)
					   {
						 for (int j = i + 1; j < player.size(); ++j)
				          {
					       if (player[i].first == player[j].first) return true;
				           }
			            }
		            }
	
      
			return false;
	}
//----------------------------------------------------------------------------------------------------------------------
	int _Two_Pair()//��� ����
	{
		int pair1 = 0;
		int pair2 = 0;
		int pos = 0;

		for (int i = 0; i < player.size(); i++)
		{
			for (int j = i + 1; j < player.size(); j++)
			{
				if (player[i].first == player[j].first && !pair1) { pair1 = 1; pos = i + 2; }
				else if (pair1 == 1)
					i = 4;
			}
		}
		if (pair1 == 1 && pos < player.size())
		{
			for (int i = pos; i < player.size(); ++i)
			{
				for (int j = i + 1; j < player.size(); ++j)
				{
					if (player[i].first == player[j].first) return player[i].first;
				}
			}
		}
	}
//====================================================================================================================
	bool Three_of_a_kind()//��� ����� ������ �����
	{
		int count = 0;
	   for (int i = 0; i < 5; i++)
			{
				if (player[i].first == player[i+1].first && player[i + 1].first== player[i+2].first)count++;
				
			} 
		if (count == 1)return true;
		return false;
}
//--------------------------------------------------------------------------------------------------------------------------
	int _Three_of_a_kind()//��� ����� ������ �����
	{
		int count = 0;
		for (int i = 0; i < 5; i++)
		{
			if (player[i].first == player[i + 1].first && player[i+1].first == player[i+2].first)return player[i].first;
		}
	}
//====================================================================================================================
	bool Four_of_a_Kind()//������ ����� ������ �����
	{
		int count = 0;
		for (int i = 0; i < 4; i++)
		{
			if (player[i].first == player[i + 1].first && player[i + 1].first == player[i + 2].first && player[i+2].first==player[i+3].first)count++;
        }
		if (count == 1)return true;
		return false;
	}

//-------------------------------------------------------------------------------------------------------------------
	int _Four_of_a_Kind()//������ ����� ������ �����
	{
		
		for (int i = 0; i < 4; i++)
		{
			if (player[i].first == player[i + 1].first && player[i + 1].first == player[i + 2].first && player[i + 2].first == player[i + 3].first) return player[i].first;

		}
		
	}
//==========================================================================================================================
	bool Straight()//5 ���� ������
	{
		
		for (int i = 0; i < player.size()-4; i++)
		{
			if ((player[i].first + 1) == player[i + 1].first &&
				(player[i + 1].first + 1) == player[i + 2].first &&
				(player[i + 2].first + 1) == player[i + 3].first &&
				(player[i + 3].first + 1) == player[i + 4].first &&
				(player[i + 4].first + 1) == player[i + 5].first)return true;
			
		}
		return false;
	}
//===============================================================================================================
	bool Flush()//5 ���� ����� �����
	{
		int count = 0;
		for (int i = 0; i < 4; i++)
		{ 
			if (count != 0)count = 0;
			for (int j = 0; j < player.size(); j++)
			{
				if (player[j].second == SUITS[i])count++; 
                if (count == 5)return true;
			}
		}
       return false;
	}
//==========================================================================================================
	bool Full_House()//��� ����� ������ ����� + ��� ����� ������� �����
	{ 
		int ranks_1 = 0;
		int ranks_2 = 0;
	
		for (int i = 0; i < player.size(); i++)
		{
			if (ranks_1 != 2)ranks_1 = 0;
			for (int j = i+1; j < player.size(); j++)
			{
				if (player[i].first == player[j].first)ranks_1++;
			}
			if(ranks_1==2)i = 6;
	     }
		if (ranks_1 == 2)
		{
			for (int i = 0; i < 4; i++)
			{
				if (ranks_2 != 3)ranks_2 = 0;
				for (int j =i+1; j < player.size(); j++)
				{
					if (player[i].first == player[j].first && !ranks_1)ranks_2++;
				}
				if (ranks_2 == 3)return true;
			}
		}
		return false;

	}
//=======================================================================================================================
	bool Straight_flush()
	{
		if (Flush() == true && Straight() == true)return true;
		else return false;
	}
//========================================================================================================================
	bool Royal_Flush()//10,J,Q,K,A
	{
		int count = 0;
		int sum = 0 ;
		for (int j = 0; j < 5; j++)
		{
			if (count != 0)count = 0;
			for (int i = 0; i < player.size(); i++)
			{
				if (player[i].first == RANKS[j + 8]) count++;
				if (count == 1) { sum += count; i = 6; }
			}

		}
			if (sum == 5 && Flush() == 1)return true;
			else
		return false;
	}
//========================================================================================================
	string Find_winner()
	{
		if (Royal_Flush() == 1) return "<Royal_Flush>";
		if (Straight_flush() == 1) return "<Straight Flush>";
		if (Four_of_a_Kind() == 1) return "<Four of a Kind>";
		if (Full_House() == 1) return "<Full House>";
		if (Flush() == 1) return "<Flush>";
		if (Straight() == 1) return "<Straight>";
		if (Three_of_a_kind() == 1) return "<Three of a kind>";
		if (Two_Pair() != 0) return "<Two pair>";
	    if (One_Pair() != 0)return "<One pair>";
		else
			return "<Is not a winning set of cards>";

		}
//-----------------------------------------------------------------------------------------------------------------
	int Find_winner_int()
	{
		int count = 0;
		
		count++; if (Royal_Flush() == 1) return count;
		count++; if (Straight_flush() == 1) return count;
		count++; if (Four_of_a_Kind() == 1) return count;
		count++; if (Full_House() == 1) return count;
		count++; if (Flush() == 1) return count;
		count++; if (Straight() == 1) return count;
		count++; if (Three_of_a_kind() == 1)return count;
		count++; if (Two_Pair() != 0) return count;
		count++; if (One_Pair() != 0)return count;
		else
			return 10;
	
	}
//---------------------------------------------------------------------------------------------------------------------
	int Find_winner_int_10(Player &comp)
	{
		if (this->find_card_first(7) == comp.find_card_first(7))
		{
		if (this->find_card_first(6) == comp.find_card_first(6))
		{
		if (this->find_card_first(5) == comp.find_card_first(5))
		{
		if (this->find_card_first(4) == comp.find_card_first(4))
		{
		if (this->find_card_first(3) == comp.find_card_first(3))
		{
		if (this->find_card_first(2) > comp.find_card_first(2))
		{
					cout << "I won!";
					cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return this->find_card_first(2);
		}
		else
		{
				    cout << "Comp won!";
					cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return comp.find_card_first(2);
		}
		}
					
//i=3----------------------------------------------------------------------------------------
			if (this->find_card_first(3) > comp.find_card_first(3))
			{
					cout << "I won!";
					cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return this->find_card_first(3);
			}
			else
			{
					cout << "Comp won!";
					cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return comp.find_card_first(3);
			}
			}
//i=4---------------------------------------------------------------------------------
			if (this->find_card_first(4) > comp.find_card_first(4))
			{
					cout << "I won!";
					cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return this->find_card_first(4);
			}
			else
			{
				    cout << "Comp won!";
				    cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				    return comp.find_card_first(4);
			}
			}
//i=5--------------------------------------------------------------------------
			if (this->find_card_first(5) > comp.find_card_first(5))
			{
					cout << "I won!";
					cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return this->find_card_first(5);
			}
			else
			{
					cout << "Comp won!";
					cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return comp.find_card_first(5);
			}
			}
//i=6----------------------------------------------------------------------
			if (this->find_card_first(6) > comp.find_card_first(6))
			{
				cout << "I won!";
				cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return this->find_card_first(6);
			}
			else
			{
				cout << "Comp won!";
				cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return comp.find_card_first(6);
			}
		}
//i=7---------------------------------------------------------------------------------------
		if (this->find_card_first(7) > comp.find_card_first(7))
		{
			cout << "I won!";
			cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
			return this->find_card_first(7);
		}
		else
		{
			cout << "Comp won!";
			cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
			return comp.find_card_first(7);
		}
	}
	
//---------------------------------------------------------------------------------------------------------------------	
	int Who_did_win(Player &comp)
	{
		if (this->Find_winner_int() == 10 && comp.Find_winner_int() == 10)//���� ��� ���������� ���������� ������� ������� �����
		{
			return Find_winner_int_10(comp);
		}
        if (this->One_Pair() == 1 && comp.One_Pair() == 1)//���� �� ����� ���� 
			{
			if (this->_One_Pair() == comp._One_Pair())
			{
					return Find_winner_int_10(comp);
			}
			if (this->_One_Pair() > comp._One_Pair())
			{
				cout << "I won!";
				cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return this->_One_Pair();
			}
		else
			{
				cout << "Comp won!";
				cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return comp._One_Pair();
			}
			}
		else
			if (this->Two_Pair() == 1 && comp.Two_Pair() == 1)//���� �� ��� ����
			{
				if (this->Two_Pair() == comp.Two_Pair())
				{
					return Find_winner_int_10(comp);
				}
                if (this->_Two_Pair() > comp._Two_Pair())
				{
				   cout << "I won!";
				   cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				   return this->Two_Pair();
				}
				else
				{
					cout << "Comp won!";
					cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return comp.Two_Pair();
				}
				}
				else
				if (this->Three_of_a_kind() == 1 && comp.Three_of_a_kind() == 1)//���� �� ��� ���������� �����
				{
					if (this->_Three_of_a_kind() > comp._Three_of_a_kind())
					{
				    	cout << "I won!";
						cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return this->_Three_of_a_kind();
					}
				else
					{
					   cout << "Comp won!";
					   cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					   return comp._Three_of_a_kind();
				    }
					}
				else
					if (this->Four_of_a_Kind() == 1 && comp.Four_of_a_Kind() == 1)//���� �� ������ ���������� �����
					{
					  if (this->_Four_of_a_Kind() > comp._Four_of_a_Kind())
						{
						  cout << "I won!";
						  cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						  return this->_Four_of_a_Kind();
						}
					else
					   {
						   cout << "Comp won!";
						   cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						   return comp._Four_of_a_Kind();
						}
					 }
				   else
					if (this->Straight() == 1 && comp.Straight() == 1)
					{
					    return Find_winner_int_10(comp);
					}
					else
					if (this->Flush() == 1 && comp.Flush() == 1)
					 {
						return Find_winner_int_10(comp);
					 }
				   else
				    	if (this->Full_House() == 1 && comp.Full_House() == 1)
						{
							return Find_winner_int_10(comp);
						}

	}

	
};


//====================================================================================================================
void main()
{
	srand(time(0));
	Deck_of_cards obj;
	obj._Deck();
    cout << "\n";
	cout << "\t\t\tDECK OF CARD.\n";
	obj.Show();
	cout << "\n";
	cout << "=============================================================================================================\n\n";
	
		char answer;
		char n, y;
		cout << "\t\tDo you want to play poker?\n\n";

		cout << "Press 'y' if 'yes' or 'n' if 'no'.\n";
		cin >> answer;
		
	
		if (answer == 'n') cout << "Bye!Bye!\n";
       else
			do
			{
				system("cls");
				Player my;
				Player comp;
				Player diler;
		        int money = 0;
//--------------------------------------------------------------------------------------------------------				
				cout << "\n";
				cout << "You are bets: "; cin >> money;

				my.set_Bet(money);
				comp.set_Bet(money);
//--------------------------------------------------------------------------------------------------------
				my.Start_hand(obj);
				comp.Start_hand(obj);
			    cout << "\n\n";
				cout << "\tMy cards.\n\n";
				my.Show_cards();
				cout << "\n";
				//my.Show_one_card();
				cout << "\n";
	            cout << "---------------------------------------------------------------------------------------------------------------\n\n";
				cout << "\tComp cards.\n\n";
				comp.Show_cards();
				cout << "\n";
				cout << "================================================================================================================\n\n";
				
//--------------------------------------------------------------------------------------------------------------				
				int check;
				cout << " Do you want to continue the game? "; cin >> answer;
				if (answer == 'n')
				{
					cout << "Comp won!\n";
					cout << "Comp money = " << my.get_Bet() + comp.get_Bet() << "$\n";
					cout << "Bye!Bye!\n";
				}
				else
				{
					cout << "If you want to skip bet, press : 1\n";
					cout << "If you want to raise your bet, press : 2\n";
					cin >> check;
					switch (check)
					{
					case 1: {
                              my.Raise_bet(0);
						      comp.Raise_bet(0);
					        }break;
					case 2: {
						        int new_bet = 0;
								cout << "Input new bet "; cin >> new_bet;
								my.Raise_bet(new_bet);
								comp.Raise_bet(new_bet);
					         }break;
				     }

				}
			
//-----------------------------------------------------------------------------------------------------------------
				cout << "========================================================================================================\n";
				cout << setw(20) << "CARDS ON THE TABLE\n";
				diler.Flop(obj);
				diler.Show_cards();
				cout << "=====================================================================================================\n";
//--------------------------------------------------------------------------------------------------------------------------				
				cout << " Do you want to continue the game? "; cin >> answer;
				if (answer == 'n')
				{
					cout << "Comp won!\n";
					cout << "Comp money = " << my.get_Bet() + comp.get_Bet() << "$\n";
					cout << "Bye!Bye!\n";
				}
				else
				{
					cout << "If you want to skip bet, press : 1\n";
					cout << "If you want to raise your bet, press : 2\n";
					cin >> check;
					switch (check)
					{
					case 1: {
						my.Raise_bet(0);
						comp.Raise_bet(0);
					}break;
					case 2: {
						int new_bet = 0;
						cout << "Input new bet "; cin >> new_bet;
						my.Raise_bet(new_bet);
						comp.Raise_bet(new_bet);
					}break;
					}

				}
//---------------------------------------------------------------------------------------------------------------------				
				cout << "========================================================================================================\n";
				cout << setw(20) << "CARDS ON THE TABLE\n";
				diler.Start_hand(obj);
				diler.Show_cards();

				cout << "================================================================================================================\n\n";
				cout << "\tMy cards.\n";
				my.Diler_card_to_player(diler);
				my.Show_cards();

				//my.Show_one_card();
				cout << "\n\n";
              cout << "My set of cards :" << my.Find_winner() << "\n";
				cout << "-----------------------------------------------------------------------------------------------------------------\n\n";
				cout << "\tComp cards.\n";
				comp.Diler_card_to_player(diler);
				comp.Show_cards();
				//comp.Show_one_card();
				cout << "\n\n";
              cout << "Comp set of cards :" << comp.Find_winner() << "\n";
				cout << "================================================================================================================\n\n";
				
				if (my.Find_winner_int() == comp.Find_winner_int())
				{
					cout << my.Who_did_win(comp);
				}

               if (my.Find_winner_int() < comp.Find_winner_int())
				{

					cout << "I won!";
					cout << "My money = " << my.get_Bet() + comp.get_Bet() << "$\n";
				}
			    if (my.Find_winner_int() > comp.Find_winner_int())
				{
					cout << "Comp won!";
					cout << "Comp money = " << my.get_Bet() + comp.get_Bet() << "$\n";
				}

				cout << "\n\n";
				cout << "Do you want to play again?"; cin >> answer;

			} while (answer == 'y');
	}
	
	