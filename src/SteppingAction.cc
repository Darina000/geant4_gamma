//
//  SteppingAction.cpp
//  
//
//  Created by Дарья Землянская on 24.07.2020.
//

#include "G4Step.hh"
#include "G4ParticleTypes.hh"
#include "G4RunManager.hh"
#include "G4Run.hh"
#include <G4ParticleGunMessenger.hh>
#include <G4ParticleGun.hh>

#include "SteppingAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"


#include "Analysis.hh"

#include "G4EmCalculator.hh"

#include "Randomize.hh"
#include <iomanip>

using namespace std;
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::SteppingAction(RunAction* RA, EventAction* EA)
:G4UserSteppingAction(),fRunaction(RA), fEventaction(EA)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

SteppingAction::~SteppingAction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
    G4VPhysicalVolume* volume
    = aStep->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    
    G4StepPoint* prePoint = aStep->GetPreStepPoint();
    G4StepPoint* postPoint = aStep->GetPostStepPoint();
    
    G4double kinEnergyPreStep = prePoint->GetKineticEnergy();
    G4double kinEnergyPostStep = postPoint->GetKineticEnergy();
    
    cout << kinEnergyPreStep << " " <<  kinEnergyPostStep ;
    G4double raz = kinEnergyPreStep - kinEnergyPostStep;
    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
    
    G4double edep = aStep->GetTotalEnergyDeposit();

    if (raz != 0){
     analysisManager->FillNtupleDColumn(0, raz);
     //  cout << "added  "  <<  edep << "  parent id" <<  parentID << endl;
      
   }
    analysisManager->FillNtupleDColumn(1, edep);
    analysisManager -> AddNtupleRow();
    
    }
