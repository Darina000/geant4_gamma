//
//  DetectorConstruction.cpp
//  
//




//  Created by Дарья Землянская on 19.07.2020.
//
#include "G4NistManager.hh"
#include "DetectorConstruction.hh"
#include "SensitiveDetector.hh"
#include <G4NistManager.hh>
#include <G4SDManager.hh>
#include <G4VisAttributes.hh>
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"
#include "G4MultiFunctionalDetector.hh"
#include "G4VPrimitiveScorer.hh"
#include "G4VisAttributes.hh"
#include "G4PhysicalConstants.hh"
#include "G4SystemOfUnits.hh"
#include "G4VPhysicalVolume.hh"
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4VSolid.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

using namespace std;


#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{
    G4String name, symbol;
    G4double a, z;
    G4double density, fractionmass;
    G4int nel, ncomponents;
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  

  G4bool isotopes = true;
  
  G4Element*  La = nist->FindOrBuildElement("La" , isotopes);
  G4Element* Br = nist->FindOrBuildElement("Br", isotopes);
  
  G4Material* LaBr3 = new G4Material("LaBr3", 5.06*g/cm3, 2);
  LaBr3->AddElement(La, 1);
  LaBr3->AddElement(Br, 3);
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

    

  //
  // World
  //
  G4double world_sizeXY = 7*cm;
  G4double world_sizeZ  = 30*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");
  
  G4Box* solidWorld =
    new G4Box("World",                       //its name
       world_sizeXY, world_sizeXY, world_sizeZ);     //its size
      
  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      checkOverlaps);        //overlaps checking
                     
  //
  // Envelope
  //
  G4Box* solidDet =
    new G4Box("Envelope",                    //its name
              6*cm, 6*cm, 3.5*mm); //its size
      
  G4LogicalVolume* logicDet =
    new G4LogicalVolume(solidDet,            //its solid
                        LaBr3,             //its material
                        "Det");         //its name
               
  new G4PVPlacement(0,                       //no rotation
                    G4ThreeVector(),         //at (0,0,0)
                    logicDet,                //its logical volume
                    "Det",              //its name
                    logicWorld,              //its mother  volume
                    false,                   //no boolean operation
                    0,                       //copy number
                    checkOverlaps);          //overlaps checking
 

    
  SensitiveDetector *detector = new SensitiveDetector("SensDet");
  
  G4SDManager* SDman = G4SDManager::GetSDMpointer();
  SDman->AddNewDetector(detector);
    
  logicDet->SetSensitiveDetector(detector);
  
  logicWorld->SetVisAttributes (G4VisAttributes::Invisible);

  return physWorld;
}

