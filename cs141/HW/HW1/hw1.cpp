#include<iostream>//i have abreviated road runner with RR wileECoyote with WEC
			// and i have renamedlair to lair distance to  distance
int main()
{
// given info

	int RRSpeed = 15; //road runner speed
	int Distance = 30; //distance between lairs
	int RRBreak = 15; //road runner break time

//calcutations 

	short RRTravelTime = (Distance / RRSpeed) * (60) + (RRBreak); // road runner travel time
	short WECTravelTime = (RRTravelTime - 5); // Coyote travel time calculation
	float WECSpeed = (float(Distance) / float(WECTravelTime)) * 60;// Coyote speed calculation

// print function

	std::cout <<"The speed that Wile E Coyote travels at ="<< WECSpeed <<"mph"<< std::endl;

// end program
	return 0;
}
