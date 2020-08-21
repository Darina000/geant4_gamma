//
//  EventAction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//
#include <RunAction.hh>
#include "EventAction.hh"
#include "RunAction.hh"
#include "Analysis.hh"
#include "SensitiveDetector.hh"
#include "PrimaryGeneratorAction.hh"
#include "TrackingAction.hh"

#include "G4Event.hh"
#include "G4TrajectoryContainer.hh"
#include "G4ios.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include "TH1.h"
#include <time.h>
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4HCofThisEvent.hh"
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>
#include "G4RunManager.hh"
#include "G4Run.hh"
#include <G4ParticleGunMessenger.hh>
#include <G4ParticleGun.hh>

extern double edep;
int Evt_Number;

using namespace std;


EventAction::EventAction(RunAction* RA, PrimaryGeneratorAction* prim)
:G4UserEventAction(),fRunAction(RA), primary(prim)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event* evt)
{
    
 //   G4int evtNb = evt->GetEventID();
 //   G4cout << "\n---> Begin of event: " << evtNb << G4endl;
  //  edep=0;
    
   //fEdepPrimary = fEdepSecondary = 0.;
    cout << "................" << G4endl;
    
    //cout << evt->GetEventID() << G4endl;
    //cout << G4Event << G4endl;
  //  G4ParticleGun* gun = primary->GetParticleGun();
 //  G4double ekin = gun->GetParticleEnergy();
   // cout << "ekit" << "  "  << ekin << G4endl;  //  получаем энергию начальную

}

void EventAction::EndOfEventAction(const G4Event* evt){
}




  




