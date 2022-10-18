/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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

    double sellMonthlyPass(Member member, double price = 29.99, int numMonths = 6);
    void setPersonalTrainer(std::string trainerName, float sessionLength = 2.5f, double sessionTime = 1000);
    double getUserFreq(double peopleDaily, int numDays = 30);
    void checkIncome(double peopleDaily, int numDays, double price);
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

double Gym::sellMonthlyPass(Gym::Member, double price, int numMonths)
{
    return price * numMonths;
}

void Gym::setPersonalTrainer(std::string trainerName, float sessionLength, double sessionTime)
{

    std::cout << "You have scheduled a session with: " << trainerName << "\n" << "at: " << sessionTime << "\n" << "for: " << sessionLength << " hours\n";
}

double Gym::getUserFreq(double peopleDaily, int numDays)
{
    return peopleDaily / numDays;
}

void Gym::checkIncome(double peopleDaily, int numDays, double price)
{
    for(auto i = numDays; i <= 90; i += numDays)
    {
        std::cout << "the average income for " << i << " days is: " << (peopleDaily * price) / i << "\n";
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

    double playNote(int keyNum, double playLength = 45.0);
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

double Piano::playNote(int keyNum, double playLength)
{
    /*
    std::cout << "what key would you like to play? (insert key number)\n";
    std::cin >> numKey;
    std::cout << "how long would you like to play the note? (insert time in ms)\n";
    std::cin >> playTime;
    */
    this->notePlayed = playLength * keyNum;
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
    int oscillatorNum = 1;
    float amplifier = 45.0f;
    double modulator = 24.5;
    std::string title = "Wave Generator 1";
    double filter = 35.75;
    double sineWaveFreq = 440;

    WaveGenerator();
    ~WaveGenerator();

    void genSineWave(double waveFreq, int waveOsc = 1);
    double modWave(int waveModType = 4, std::string waveModName = "Ring Mod");
    double filterWave(double filterFreq, int filterType = 3, double filterSlope = 12.0);
    void distort(int waveFreq, int distortion, int scale);
};

WaveGenerator::WaveGenerator()
{
    std::cout << "WaveGenerator Constructed \n";
}

WaveGenerator::~WaveGenerator()
{
    std::cout << "WaveGenerator Deconstructed \n";
}

void WaveGenerator::genSineWave(double waveFreq, int waveOsc)
{
    this->sineWaveFreq = waveFreq * waveOsc;
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

void WaveGenerator::distort(int waveFreq, int distortion, int scale)
{
    for( ; waveFreq <= distortion; waveFreq *= scale)
    {
        std::cout << "applying distortion at: " << waveFreq << "hz \n";
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

    int tallyGymChainCounter(int numChainLocations, int numFranchiseLocations);
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

int GymChain::tallyGymChainCounter(int numChainLocations, int numFranchiseLocations)
{
    this->gymCounter = numChainLocations + numFranchiseLocations;
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
    float modulate (float prmtr1, float prmtr2, float prmtr3);
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

float Synthesizer::modulate(float prmtr1, float prmtr2, float prmtr3)
{
    this->lfo = prmtr1 * prmtr2 / prmtr3;
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
    std::cout << "sine wave frequency is: " << waveGen.sineWaveFreq * waveGen.oscillatorNum << "\n";
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
