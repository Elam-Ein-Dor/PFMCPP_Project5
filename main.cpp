/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

/*
copied UDT 1:
*/
struct Gym
{
    double numShowers = 40;
    double numWeights = 120;
    double subscriptionPrice = 29.99;
    std::string personalTrainerName = "Fred";
    double numDailyPeople = 45.5;
    int gymCounter = 1;
    
    Gym();
    ~Gym();

    struct Member
    {
        int age = 25;
        std::string memberName = "Ethan";
        float memberBMI = 17.f;
        std::string subscriptionType = "Daily Passes";
        int passesLeft = 34;

        Member();
        ~Member();

        void punchPass(int passesLeft);
        bool bringAFriend(bool hasFriendPass = true, int friendPassType = 2);
        int giveReward(int subsctiptionType, std::string rewardName = "10% Discount", int rewardAmount = 10);
        void trackProgress(int goal, int passesRemaining);
    };

    double sellMonthlyPass(Member member, double mSubscriptionPrice = 29.99, int numMonths = 6);
    void setPersonalTrainer(std::string mPersonalTrainerName, float sessionLength = 2.5f, double sessionTime = 1000);
    double getUserFreq(double mNumDailyPeople, int numDays = 30);
    void checkIncome(double mNumDailyPeople, int numDays, double mSubscriptionPrice);
    void printUserFreq();
};

Gym::Gym()
{
    std::cout << "Gym Constructed \n";
}

Gym::~Gym()
{
    std::cout << "Gym Deconstructed \n";
}

Gym::Member::Member()
{
    std::cout << "Gym::Member Constructed \n";
}

Gym::Member::~Member()
{
    std::cout << "Gym::Member Deconstructed \n";
}

double Gym::sellMonthlyPass(Gym::Member, double mSubscriptionPrice, int numMonths)
{
    subscriptionPrice = mSubscriptionPrice;
    double totalPrice = subscriptionPrice * numMonths;
    return totalPrice;
}

void Gym::setPersonalTrainer(std::string mPersonalTrainerName, float sessionLength, double sessionTime)
{
    mPersonalTrainerName = "Dave";
    sessionLength = 1.5f;
    sessionTime = 2;

    std::cout << "You have scheduled a session with: " << mPersonalTrainerName << "\n" << "at: " << sessionTime << "\n" << "for: " << sessionLength << " hours\n";
}

double Gym::getUserFreq(double mNumDailyPeople, int numDays)
{
    double userFreq = mNumDailyPeople / numDays;
    return userFreq;
}

void Gym::checkIncome(double mNumDailyPeople, int numDays, double mSubscriptionPrice)
{
    for(auto i = numDays; i <= 90; i += numDays)
    {
        std::cout << "the average income for " << i << " days is: " << (mNumDailyPeople * mSubscriptionPrice) / i << "\n";
    }
}

void Gym::printUserFreq()
{
    std::cout << "average user number is: " << this->getUserFreq(45, 30) << ", today there were: " << this->numDailyPeople << "\n";
}

void Gym::Member::punchPass(int passesRemaining)
{
    this->passesLeft = passesRemaining -= 1;
    std::cout << "you have " << this->passesLeft << " passes left!\n";
}

bool Gym::Member::bringAFriend(bool hasFriendPass, int friendPassType)
{
    if (hasFriendPass == true)
    {
        passesLeft -= 1;
    }

    std::cout << "you used " << friendPassType << " and have " << passesLeft << " passes left\n";
    return hasFriendPass;
}

int Gym::Member::giveReward(int subsctiptionType, std::string rewardName, int rewardAmount)
{
    if (subsctiptionType >= 4; subsctiptionType < 8)
    {
        rewardName = "10% discount";
        rewardAmount = 10;
    }
    else if (subsctiptionType >8)
    {
        rewardName = "20% discount";
        rewardAmount = 20;
    }
    else
    {
        rewardName = "none";
        rewardAmount = 0;
    }
    
    return rewardAmount;
}

void Gym::Member::trackProgress(int goal, int passesRemaining)
{
    for(auto i = 0; i < goal; ++i)
    {
        std::cout << "you are " << goal - i << " (insert parameter here) away from your goal of: " << goal << "\n";
        --passesRemaining;
        std::cout << "you have " << passesRemaining << " passes left \n";
    }
    std::cout << "you have reached your goal!!! \n";
    --passesRemaining;
    std::cout << "you also have " << passesRemaining << " passes left \n";
}

// copied UDT 2:
struct Piano
{
    int totalNumKeys = 88;
    std::string pianoType = "Grand Piano";
    double pianoSize = 20.80;
    std::string brandName = "Yamaha";
    int totalNumPedals = 3;
    int numKey = 40;
    double playTime = 42.25;
    double notePlayed;

    Piano();
    ~Piano();

    double playNote(int mNumKey, double mPlayTime = 45.0);
    int muteNote(bool playOrMute = false, bool stringPadOn = true);
    void turnVolumeDown(bool quietMode = true, int numPedal = 2);
    void arpeggiate(int keyNum, int range, int interval);
};

Piano::Piano()
{
    std::cout << "Piano Constructed \n";
}

Piano::~Piano()
{
    std::cout << "Piano Deconstructed \n";
}

double Piano::playNote(int mNumKey, double mPlayTime)
{
    /*
    std::cout << "what key would you like to play? (insert key number)\n";
    std::cin >> numKey;
    std::cout << "how long would you like to play the note? (insert time in ms)\n";
    std::cin >> playTime;
    */
    this->notePlayed = mPlayTime * mNumKey;
    std::cout << "now playing note " << notePlayed << "\n";
    return notePlayed;
}

int Piano::muteNote(bool playOrMute, bool stringPadOn)
{
    if (playOrMute == false)
    {
        return 0;
    }
    else
    {
        if (stringPadOn == true)
        {
            return 50;
        }
    }    
    return 100;
}

void Piano::turnVolumeDown(bool quietMode, int numPedal)
{
    if (quietMode == true)
    {
        if (numPedal == 1)
        {
            std::cout << "volume has changed to 50\n";
        }
        else if (numPedal == 2)
        {
            std::cout << "volume has changed to 25\n";
        }
        else
        {
            std::cout << "volume has changed to 75\n";
        }
    }
    std::cout << "volume has changed to 0\n";
}

void Piano::arpeggiate(int keyNum, int range, int interval)
{
    range = keyNum + range;
    std::cout << "your arpeggio would consist of the following notes: ";
    for( ; keyNum <= range; keyNum += interval)
    {
        std::cout << keyNum << ", ";
    }
    std::cout << "try it out! \n";
}

//copied UDT 3:
struct WaveGenerator
{
    int oscillator = 1;
    float amplifier = 45.0f;
    double modulator = 24.5;
    std::string title = "Wave Generator 1";
    double filter = 35.75;
    double sineWaveFreq = 440;

    WaveGenerator();
    ~WaveGenerator();

    void genSineWave(double mSineWaveFreq, int mOscillator = 1);
    double modWave(int waveModType = 4, std::string waveModName = "Ring Mod");
    double filterWave(double filterFreq, int filterType = 3, double filterSlope = 12.0);
    void distort(int mSineWaveFreq, int distortion, int scale);
};

WaveGenerator::WaveGenerator()
{
    std::cout << "WaveGenerator Constructed \n";
}

WaveGenerator::~WaveGenerator()
{
    std::cout << "WaveGenerator Deconstructed \n";
}

void WaveGenerator::genSineWave(double mSineWaveFreq, int mOscillator)
{
    this->sineWaveFreq = mSineWaveFreq * mOscillator;
    std::cout << "sine wave frequency is: " << sineWaveFreq << "\n";
}

double WaveGenerator::modWave(int waveModType, std::string waveModName)
{
    waveModType = 1;
    waveModName = "ring";
    return 20;
}

double WaveGenerator::filterWave(double filterFreq, int filterType, double filterSlope)
{
    if (filterType == 1)
    {
        filterSlope = 12;
    }
    else if (filterType == 2)
    {
        filterSlope = 24;
    }
    else
    {
        filterSlope = 6;
    }

    // std::cin >> filterFreq;
    return filterFreq * filterSlope;
}

void WaveGenerator::distort(int mSineWaveFreq, int distortion, int scale)
{
    for( ; mSineWaveFreq <= distortion; mSineWaveFreq *= scale)
    {
        std::cout << "applying distortion at: " << mSineWaveFreq << "hz \n";
    }
}

/*
 new UDT 4:
 with 2 member functions
 */
struct GymChain
{
    Gym gym;
    Gym::Member member1;
    Gym::Member member2;
    int gymCounter = 1;
    int chainLocations = 10;
    int franchiseLocations = 17;

    GymChain();
    ~GymChain();

    int tallyGymChainCounter(int mChainLocations, int mFranchiseLocations);
    double forecastProfit(int totalGymLocations, int membershipPrice, int totalMembers);
};

GymChain::GymChain()
{
    std::cout << "GymChain Constructed \n";
}

GymChain::~GymChain()
{
    std::cout << "GymChain Deconstructed \n";
}

int GymChain::tallyGymChainCounter(int mChainLocations, int mFranchiseLocations)
{
    this->gymCounter = mChainLocations + mFranchiseLocations;
    std::cout << "the total number of locations in the chain is: " << gymCounter << "\n";
    return gymCounter;
}

double GymChain::forecastProfit(int totalGymLocations, int membershipPrice, int totalMembers)
{
    double expenses = totalGymLocations * 0.3 * 1500;
    double revenue = membershipPrice * totalMembers * 0.6;
    std::cout << "Profit Forecast is: " << revenue - expenses << "\n";
    return revenue - expenses;
}

/*
 new UDT 5:
 with 2 member functions
 */
struct Synthesizer
{
    Piano piano;
    WaveGenerator oscillator;
    float lfo;
    float param1 = 10.0f;
    float param2 = 13.3f;
    float param3 = 3.7f;
    Synthesizer();
    ~Synthesizer();

    void playNote (int noteLength, int frequency);
    float modulate (float mParam1, float mParam2, float mParam3);
};

Synthesizer::Synthesizer()
{
    std::cout << "Synthesizer Constructed \n";
}

Synthesizer::~Synthesizer()
{
    std::cout << "Synthesizer Deconstructed \n";
}

void Synthesizer::playNote(int noteLength, int frequency)
{
    std::cout << "now playing a note at " << frequency << "hz, for " << noteLength << "ms.\n" << "enjoy! \n";
}

float Synthesizer::modulate(float mParam1, float mParam2, float mParam3)
{
    this->lfo = mParam1 * mParam2 / mParam3;
    std::cout << "modulating the signal now at: " << lfo << "hz \n";
    return lfo;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Gym crushIt;
    crushIt.setPersonalTrainer("chuck", 2.5f, 1000);
    Gym::Member example;
    crushIt.sellMonthlyPass(example, 29.99, 6);
    std::cout << "average user number is: " << crushIt.getUserFreq(45, 30) << ", today there were: " << crushIt.numDailyPeople << "\n";
    crushIt.printUserFreq();
    crushIt.checkIncome(34, 30, 24.99);
    
    Gym::Member patron;
    std::cout << "you have " << patron.passesLeft << " passes left!\n";
    patron.punchPass(5);
    patron.bringAFriend(true, 4);
    patron.giveReward(1, "10% Discount", 10);
    patron.trackProgress(2, 10);
    
    Piano grandPiano;
    grandPiano.turnVolumeDown(false, 1);
    std::cout << "now playing note " << grandPiano.numKey * grandPiano.playTime << "\n";
    grandPiano.playNote(40, 42.25);
    grandPiano.muteNote(false, false);
    grandPiano.arpeggiate(40, 4, 1);
    
    WaveGenerator waveGen;
    std::cout << "sine wave frequency is: " << waveGen.sineWaveFreq * waveGen.oscillator << "\n";
    waveGen.genSineWave(250, 3);
    waveGen.modWave(4, "Ring");
    waveGen.filterWave(500, 2, 18.0);
    waveGen.distort(500, 20000, 3);
    
    GymChain powerHour;
    powerHour.forecastProfit(75, 50, 10000);
    std::cout << "the total number of locations in the chain is: " << powerHour.chainLocations + powerHour.franchiseLocations << "\n";
    powerHour.tallyGymChainCounter(50, 25);
    
    Synthesizer synth;
    synth.playNote(50, 440);
    std::cout << "modulating the signal now at: " << synth.param1 * synth.param2 / synth.param3 << "hz \n";
    synth.modulate(10.0, 25.0, 3.5);
    
    std::cout << "good to go!" << std::endl;
}
