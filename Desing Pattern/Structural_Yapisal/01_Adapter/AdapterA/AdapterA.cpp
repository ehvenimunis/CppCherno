// AdapterA.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include<iostream>
#include<string>

using namespace std;

class IPlayer //Client wants to use this.
{
public:
	virtual void Play() = 0;	//This is function client wants to use
};

class OldPlayer	//What we have
{
	string _song;
public:
	OldPlayer(string song) :_song(song) {}

	void OldPlay(int volume)	//This is function we got 
	{
		cout << "\nPlaying song : " << _song << " at volume :" << volume << "\n";
	}
};

class Adapter : public IPlayer, private OldPlayer
{
	int _volume;
public:
	Adapter(string song, int volume) :_volume(volume), OldPlayer(song) {}

	void Play()		//Comes from public inheritance
	{
		OldPlay(_volume);	//Comes from private inheritance
	}
};

int main()
{
	IPlayer* newStuffDad = new Adapter("Tarkan", 50);
	newStuffDad->Play();	//The call to the interface function is routed by the adapter to the LegacyCode.
	cout << "\n";
	delete newStuffDad;
	return 1;
}

/*
	Playing song : Good Ole Boy Like Me at volume :50
*/