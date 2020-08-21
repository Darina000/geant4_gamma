//
//  SensitiveDetector.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//
#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include"SensitiveDetector.hh"
#include"PhysicsList.hh"
#include "TH1.h"
#include "G4HCofThisEvent.hh"
#include "G4ThreeVector.hh"
#include "G4ios.hh"
#include "globals.hh"
#include "EventAction.hh"
#include <G4Track.hh>

#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include <G4Gamma.hh>
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
#include "G4VHitsCollection.hh"
#include "G4SDManager.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>
#include "G4RunManager.hh"
#include "G4Run.hh"
#include <G4ParticleGunMessenger.hh>
#include <G4ParticleGun.hh>
#include "Analysis.hh"

#include "G4EmCalculator.hh"
#include "TH1.h"
#include "Randomize.hh"
#include <iomanip>


#include "TrackingAction.hh"
#include "G4PhysicalConstants.hh"
#include "StackingAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4VProcess.hh"

#include "G4ParticleTypes.hh"
#include "G4ios.hh"

#include<G4Step.hh>
#include<iostream>
#include"PhysicsList.hh"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"

#include "G4TrajectoryContainer.hh"
#include "G4VTrajectory.hh"
#include "G4VVisManager.hh"
#include "G4UnitsTable.hh"
#include <time.h>
#include "G4EventManager.hh"
#include "G4Trajectory.hh"
#include "G4Event.hh"
#include "G4VHitsCollection.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>
#include "G4RunManager.hh"
#include "G4Run.hh"
#include <G4ParticleGunMessenger.hh>
#include <G4ParticleGun.hh>

#include "Analysis.hh"
#include <iomanip>
using namespace std;


G4double edep;
G4double edep_step;


SensitiveDetector::SensitiveDetector(G4String name): G4VSensitiveDetector(name){
}

void SensitiveDetector::Initiaalize(G4HCofThisEvent* event)
{
    
}



G4bool SensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *history )
{
    
    // energy deposit
    G4double edep = aStep->GetTotalEnergyDeposit();
   // if (edep==0.) return false;
    G4String volumeName = aStep -> GetPreStepPoint() -> GetPhysicalVolume()-> GetName();
  //  if(volumeName != "sens_det0") return false;
    G4int trackID  = aStep->GetTrack()->GetTrackID();
    G4int parentID = aStep->GetTrack()->GetParentID();
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
     /*
    G4TouchableHandle touchable = aStep ->GetPreStepPoint()->GetTouchableHandle();
    G4int copyNo = touchable-> GetVolume(0)-> GetCopyNo();
    G4double eDep  = aStep->GetTotalEnergyDeposit();
     cout << "eDep  " << " " <<eDep   << endl;
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
   
        G4int trackID  = aStep->GetTrack()->GetTrackID();
        G4int parentID = aStep->GetTrack()->GetParentID();
        G4ThreeVector Momentum = aStep->GetPostStepPoint()->GetMomentum();
       // G4int aTrack = aStep->GetTrack()
       // if ( trackID > 1 )
       // {
           // cout << "eDep" << " " << eDep << endl;
        //cout << Momentum  << endl;
       // cout << "trackID" << " " << trackID  << endl;
       // cout << "parentID" << " " << parentID << endl;
    G4String name = aStep->GetTrack()->GetDefinition()->GetParticleName();
    G4double y = (aStep->GetTrack()->GetPosition()).y();
    G4double x = (aStep->GetTrack()->GetPosition()).x();
    G4double z = (aStep->GetTrack()->GetPosition()).z();
            
    
       // }
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    //  G4VPhysicalVolume* volume = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    
    
    G4double en = aStep->GetTrack()->GetKineticEnergy();
    edep_step = aStep->GetTotalEnergyDeposit();
    
    G4double sum = edep_step + en;
    */
// if ( ( edep_step != 0 ) /*  &&  name == "e-" */ ){
  //      cout << name  << " x, y, z: " << x << " " << y << " "<< z << "TEnD in sen" << edep_step << " -kinE_ "  << " pID " << parentID << endl;
        
   // analysisManager->FillNtupleDColumn(0, eDep );
       // analysisManager->FillNtupleDColumn(1, x);
        //analysisManager->FillNtupleDColumn(2, y);
    
     //  analysisManager -> AddNtupleRow();
    //}
    
    //cout << volume->GetName()<< "volume->GetName()" << endl;
  //  if(volume->GetName()=="sens_det0"){
    //  edep_step = aStep->GetTotalEnergyDeposit();
      //edep = edep+edep_step;
    
    //G4double en = aStep->GetTrack()->GetKineticEnergy();
    // if ((parentID == 0) && (edep_step != 0 )){
           //cout << edep_step << "- edep_step "  << " trackID " << trackID << "parentID" << parentID << endl;
    //     analysisManager->FillNtupleDColumn(0,  edep);
        //    cout << "edep_step added  "  << en + edep << endl;
            
       //   analysisManager -> AddNtupleRow();
        //  }

   // }
    
   return true;
    
}



void SensitiveDetector::EndOfEvent(G4HCofThisEvent* event)
{
    
}



SensitiveDetector::~SensitiveDetector()
{
}
