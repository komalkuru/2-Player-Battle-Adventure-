#include<iostream>
using namespace std;

class Player {
int health;
int baseDamage;

int additionalDamage;
int healCapacity;

int additionalDamageMin;
int additionalDamageMax;
int healCapacityMin;
int healCapacityMax;

int totalGivenDamage;

public:

    const string constant = " Thanks for selecting me ....... I will be loyel to you till my last breath :) ";

    int GenerateRandomAdditionalDamage( int damagemin, int damagemax ) {
    srand (time(0));
    additionalDamage = ( rand() % ( damagemax - damagemin + 1 ) + damagemin );
    return additionalDamage;
  }

  int GenerateRandomHealCapacity( int healMin,
    int healMax ) {
    srand(time(0));
    healCapacity = ( rand() % ( healMax - healMin + 1 ) + healMin );
    return healCapacity;
  }

  void Sethealth( int h ) {
    health = h;
  }

  int Gethealth() {
    return health;
  }

  void SetbaseDamage( int baseDamage1 ) {
    baseDamage = baseDamage1;
  }

  int GetbaseDamage() {
    return baseDamage;
  }

  void SetadditionalDamage( int damage ) {
    additionalDamage = damage;
  }

  int GetadditionalDamage() {
    return additionalDamage;
  }

  void SethealCapacity( int heal ) {
    healCapacity = heal;
  }

  int GethealCapacity() {
    return healCapacity;
  }

  virtual void TakingDamage( int damagereceived ) { };
  virtual int GivingAdditionalDamage() { };
  virtual void Heal() { };
};

//*****************************************************************************
class Powerful : public Player {
  public:

    Powerful() {
    Sethealth( 200 );
    SetbaseDamage( 20 );

    cout << " Hi, I'm a Powerful Player. " << endl;
    cout << " Player Health : " << Gethealth() << endl;
    cout << " Player base damage : " << GetbaseDamage() << endl;
    cout << " Additional Damage is 5 - 15 " << endl;
    cout << " Healing Capapcity is 5 - 10 " << endl << endl;
  } 

  int GivingAdditionalDamage() {
    GenerateRandomAdditionalDamage( 5, 15 );
    int totalGivenDamage = GetbaseDamage() + GetadditionalDamage();

    cout << " Additional Damage given : " << GetadditionalDamage() << endl << " Total Damage delt by Powerful Player is : " << totalGivenDamage << endl;
    return totalGivenDamage;
  }

  void TakingDamage(int damageReceived) {
    Sethealth(Gethealth() - damageReceived);
    

    if( Gethealth() ) {
      cout<<"Health of Powerful Player after receiveing damage is :"<<Gethealth()<<endl<<endl;
    }
    else {
      cout << endl << " Powerful Player - Game Over. " << endl;
      cout << " Opposite Player won the Game. " << endl << endl;
    }
  }

  void Heal() {
    Sethealth ( Gethealth() + GenerateRandomHealCapacity ( 5, 10)  );
    if ( Gethealth() >= 200 ) {
      cout << " Your health is already Full :) " << endl;
      cout << " You lost the Chance " << endl << endl;
    }
    else {
      cout << " Wooooohh!!! Powerful player using its Special Ability of Heal boost " << endl;
      cout << " Huge Heal!! by Powerful player " << endl;
      cout << " Heal boosted by : " << GethealCapacity() << endl;
      cout << " New health after Boost is : " << Gethealth() << endl << endl; 
    }   
  }
};

//**************************************************************************
class Skillful : public Player { 
  public:
  Skillful() {
    Sethealth( 150 );
    SetbaseDamage( 10 );
    cout << " Hi, I'm a Skillful Player. " << endl;
    cout << " Player Health : " << Gethealth() << endl;
    cout << " Player base damage : " << GetbaseDamage() << endl;
    cout << " Additional Damage is 6 - 16 " << endl;
    cout << " Healing Capapcity is 15 - 20 " << endl << endl;
  }

  int GivingAdditionalDamage() {
    GenerateRandomAdditionalDamage( 6, 16 );
    int totalGivenDamage = GetbaseDamage() + GetadditionalDamage();

    cout << " Additional Damage given : " << GetadditionalDamage() << endl << " Total Damage delt by Skillful Player is : " << totalGivenDamage << endl;
    return totalGivenDamage;
  }

  void TakingDamage( int damageReceived ) {
    Sethealth( Gethealth() - damageReceived );
    
    if( Gethealth() > 0 ) {
      cout << " Health of Skillful Player after receiveing damage is : " << Gethealth() << endl;
    }
    else {
      cout << " Skillful - Game Over. " << endl;
      cout << " Opposite Player won the Game. " << endl << endl;
    }
  }

  void Heal() {
    Sethealth(Gethealth() + GenerateRandomHealCapacity(15, 20));
    
    if ( Gethealth() >= 150 ) {
      cout << " Your health is already Full :) " << endl;
      cout << " You lost your chance " << endl << endl;
    }
    else {
      cout << " Wooooohh!!! Player using its Special Ability of Heal boost " << endl;
      cout << " Huge Heal!! by Player " << endl;
      cout << " Heal boosted by : " << GenerateRandomHealCapacity(5, 10) << endl;
      cout << " New health after Boost is : " << Gethealth() << endl << endl; 
    }   
  } 
};

//****************************************************************************

class Raged : public Player {
  
  public:
  Raged() {
    Sethealth( 100 );
    SetbaseDamage( 40 );
    cout << " Hi, I'm a Raged Player. " << endl;
    cout << " Player Health : " << Gethealth() << endl;
    cout << " Player base damage : " << GetbaseDamage() << endl;
    cout << " Additional Damage 8 - 18 " << endl;
    cout << " Healing Capapcity is 20 - 25 " << endl << endl;
  }

  int GivingAdditionalDamage() {
    GenerateRandomAdditionalDamage( 8, 18 );
    int totalGivenDamage = GetbaseDamage() + GetadditionalDamage();

    cout << " Additional Damage given : " << GetadditionalDamage() << endl << " Total Damage delt by Raged Player is : " << totalGivenDamage << endl;
    return totalGivenDamage;
  }

  void TakingDamage( int damageReceived ) {
    Sethealth( Gethealth() - damageReceived );
    
    if( Gethealth() > 0 ) {
      cout << " Health of Raged Player after receiveing damage is : " << Gethealth() << endl << endl;
    }
    else {
      cout << " Raged Player - Game Over. " << endl;
      cout << " Opposite Player won the Game. " << endl << endl;
    }
  }

  void Heal() {
    Sethealth( Gethealth() + GenerateRandomHealCapacity( 20, 25 ) );
    
    if ( Gethealth() >= 100 ) {
      cout << " Your health is already Full :) " << endl;
      cout << " You lost the Chance " << endl << endl;
    }
    else {
      cout << " Wooooohh!!! Player using its Special Ability of Heal boost " << endl;
      cout << " Huge Heal!! by Player " << endl;
      cout << " Heal boosted by : " << GenerateRandomHealCapacity(5, 10) << endl;
      cout << " New health after Boost is : " << Gethealth() << endl << endl; 
    }   
  } 
};
//*******************************************************************************

void ShowInstructions()
{
  cout << endl << endl;
  cout << " !! Welcome To 2-Player-Battle-Adventure Game !! " << endl << endl << endl;

  cout << "Instructions : " << endl;
  cout << "1) Each player has one choice at a time." << endl;
  cout << "2) The player can either attack or heal." << endl;
  cout << "3) The player who's health goes below 0, will die and loose the game." << endl;
  cout << "4) Press 'H' to heal and 'A' to attack." << endl;
  cout << "5) Each special ability has 20% probability." << endl << endl << endl;

  cout << "Player types :" << endl << endl ;

  cout << "1) Power Player    - High Health, Low Heal, Low Base Damage, Low Additional Damage" << endl;
  cout << "   Special Ability - Huge Heal" << endl;
  cout << "                   - Double Attack" << endl << endl;

  cout << "2) Skillful Player - Average Health, High Heal, Average Base Damage, Average Additional Damage" << endl;
  cout << "   Special Ability - Attack Blocker" << endl;
  cout << "                   - Heal + Damage in single turn" << endl << endl;

  cout << "3) Rage Player     - Low Health, Very High Heal, High Base Damage, High Additional Damage" << endl;
  cout << "   Special Ability - Rage (Damage increases when close to death)" << endl;
  cout << "                   - Critical Hit" << std::endl;

  cout << endl << endl;
} 

char CheckCorrectOption() {
  char playerChoice;
  cin >> playerChoice;
  while( true )
  {
    if( playerChoice == 'h' || playerChoice == 'H' || playerChoice == 'd' || playerChoice == 'D' )
    {
      break;
    }
    else
    {
      cout << " Invalid Input! , please give valid input " << endl;
      cout << " Please Choose Correct Option : " ;
      cin >> playerChoice;
    }
  }
  return playerChoice;
}
//**************************************************************************

void PlayerGameLoop( Player *player1, Player *player2 ) {
  do {
    char playerChoice;
    if( player1->Gethealth() > 0 ) {
      cout<< " Player 1 playing: Press D to deal Damage or H to heal yourself " << endl;

      playerChoice = CheckCorrectOption();

      if( playerChoice == 'D' || playerChoice == 'd' ) {
        cout<< " Player 2 taking damage!! " <<endl;
        player2->TakingDamage( player1->GivingAdditionalDamage() );
      }
      else if ( playerChoice == 'H' || playerChoice == 'h' ) {
        if( player1->Gethealth() > 0 ) {
          player1->Heal();
        }
      }  
    }

    if( player2->Gethealth() > 0 ) {
      cout << endl << " Player 2 playing: Press D to deal Damage or H to heal yourself " << endl;
      
      playerChoice = CheckCorrectOption();

      if(playerChoice == 'D' || playerChoice == 'd') {
        cout<< " Player 1 taking damage!! " << endl;
        player1->TakingDamage( player2->GivingAdditionalDamage() );
      }
      else if ( playerChoice == 'H' || playerChoice == 'h' ) {
        if( player2->Gethealth() > 0 ) {
          player2->Heal();
        }
      }
    }
  }while( player1 -> Gethealth() > 0 && player2 -> Gethealth() > 0 );
}

//****************************************************************************

int main() {
  ShowInstructions();
  Player *powerful = new Powerful;
  Player *skillful = new Skillful;
  Player *raged = new Raged;
  Player *player[] = { powerful, skillful, raged };
  Player p1;
  int playerChoice1, playerChoice2;
   
  cout << " Enter 1 for Powerful Player \n Enter 2 for Skillful Player \n Enter 3 for Raged Player " << endl << endl;

  cout << " Hey, Hi Player 1 : Select type of the player that you want to choose ...... :) " << endl;

  while( true ) {
    cin >> playerChoice1;
    if( !cin || !( playerChoice1==1 || playerChoice1==2 || playerChoice1==3 ) ){
    cout << " Please choice correct player type " << endl;

    cout << " Player Type : " ;
    continue;
    } 

    else {
      break;
    }
  }
  playerChoice1 = playerChoice1 - 1;
  cout << p1.constant << endl << endl;

  cout << " Hey, Hi Player 2 : Select player except the player Selected by Player 1 ...... :) " << endl;

  while(true) {
    cin>>playerChoice2;
    if(!cin || !(playerChoice2==1 || playerChoice2==2 || playerChoice2==3)){
    cout << " Please choice correct player type : " << endl;

    cout << " Player Type : ";
    continue;
    }
    else {
      break;
    }
  }

  playerChoice2 = playerChoice2 - 1;
  cout << p1.constant << endl << endl;
  PlayerGameLoop( player[playerChoice1], player[playerChoice2] );
}