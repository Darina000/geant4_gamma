//
//  RunAction.cpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"

#include "Analysis.hh"
#include "EventAction.hh"

#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4EmCalculator.hh"
#include "Randomize.hh"
#include <iomanip>

using namespace std;


RunAction::RunAction(DetectorConstruction* det, PrimaryGeneratorAction* kin)
 : G4UserRunAction(),fDetector(det), fPrimary(kin)
{
    auto analysisManager =  G4AnalysisManager::Instance();
    analysisManager->SetVerboseLevel(1);
}

RunAction::~RunAction()
{
    delete  G4AnalysisManager::Instance();
}
void RunAction::BeginOfRunAction(const G4Run* run)
{
    
     auto analysisManager =  G4AnalysisManager::Instance();
    analysisManager->OpenFile("from");
    
   // tupleId->analysisManager = analysisManager;
    analysisManager->CreateNtuple( "LT1", "jjjj" );
    analysisManager->CreateNtupleDColumn(  "energy" );
    analysisManager->CreateNtupleDColumn("energyDep");
    //analysisManager->CreateNtupleDColumn("Y");
    analysisManager->FinishNtuple();
    
}


void RunAction::EndOfRunAction(const G4Run* run){
    // Save histograms
     auto analysisManager =  G4AnalysisManager::Instance();
    analysisManager->Write();
    analysisManager->CloseFile();
    
    
    

}

