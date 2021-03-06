
#include "TrackingAction.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "EventAction.hh"
#include "G4PhysicalConstants.hh"
#include "G4Track.hh"
#include "RunAction.hh"


#include "StackingAction.hh"
#include "SensitiveDetector.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"

#include "G4Event.hh"
#include "G4VProcess.hh"

#include "G4ParticleTypes.hh"
#include "G4ios.hh"

#include<G4Step.hh>
#include<fstream>
#include<iostream>
#include"PhysicsList.hh"
#include "TH1.h"
#include "G4ThreeVector.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "globals.hh"

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

#include "G4EmCalculator.hh"

#include "Randomize.hh"
#include <iomanip>


using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

TrackingAction::TrackingAction(RunAction* runaction)
:G4UserTrackingAction(), fRunAction(runaction)
{ 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TrackingAction::PreUserTrackingAction(const G4Track* track)
{
    
   G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    G4double Ekin = track->GetKineticEnergy();
   // cout << "ttttttt" << fEkin1 << endl;
    
    G4double code = track->GetDefinition()->GetPDGEncoding();
    G4String name = track->GetDefinition()->GetParticleName();
    
  // G4double Edep = track->GetTotalEnergyDeposit();
    
   // if ((track->GetTrackID() > 1 )&& (track->GetDefinition()  == G4Electron::ElectronDefinition()) ){
              
 //   cout << "................" << G4endl;
   // cout << "pre" << endl;
    G4double z = (track->GetPosition()).z();
   // G4double eKin  = track->GetKineticEnergy();
    
    //cout << " " << name  << " Kin " << eKin << endl;
  //  cout << " " << name  << " GetTotalEnergyDeposit " << Edep << endl;
     //   cout << energy << endl;
    //G4double y = (track->GetPosition()).y();
    //G4double x = (track->GetPosition()).x();
    //    if (z > -3.5*mm && z< 3.5*mm){

 // analysisManager->FillNtupleDColumn(0, Edep);
//   analysisManager->FillNtupleDColumn(1, energy);
  //        analysisManager -> AddNtupleRow();
   // }
    //analysisManager->FillNtupleDColumn(0, z);
  //  cout << x << " " << ": = x" << endl;
  //  cout << y << " " << ": = y" << endl;
    //cout << z << " " << ": = z" << endl;
    
  //  }
}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void TrackingAction::PostUserTrackingAction(const G4Track* track){
  //energy balance of primary particle
    //
  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

