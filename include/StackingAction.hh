//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file electromagnetic/TestEm18/include/StackingAction.hh
/// \brief Definition of the StackingAction class
//
//
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#ifndef StackingAction_h
#define StackingAction_h 1

#include "G4UserStackingAction.hh"
#include "globals.hh"

#include "G4UserEventAction.hh"
#include <G4VSensitiveDetector.hh>
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include <vector>
#include <map>

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
class G4Track;
class G4VProcess;
class RunAction;
class G4ParticleDefinition;
class StackingAction : public G4UserStackingAction
{
  public:
    StackingAction();
   ~StackingAction();
    
    //void SetKillStatus(G4bool value);
   // void SetKill(const G4String& name);
    void SetTrackSecondaries(G4bool value) { fTrackSecondaries = value;};

   virtual G4ClassificationOfNewTrack ClassifyNewTrack(const G4Track*);

  private:
  // EventAction*        fEventAction; 
    G4bool              fTrackSecondaries;
 //   G4bool              fKillSecondary;
    const G4ParticleDefinition* fParticle;
    RunAction*    fRunAction;
    PrimaryGeneratorAction* primary;
    G4double      fEdepPrimary, fEdepSecondary;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

