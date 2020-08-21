//  DetectorConstruction.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include<globals.hh>
#include<G4VUserDetectorConstruction.hh>
#include<G4VSolid.hh>
#include<G4LogicalVolume.hh>
#include<G4VPhysicalVolume.hh>
#include<G4Material.hh>

class G4VPhysicalVolume;
class G4LogicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
public:
  DetectorConstruction();
  virtual ~DetectorConstruction();
  
  virtual G4VPhysicalVolume* Construct();
  G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }
protected:
  G4LogicalVolume*  fScoringVolume;
};

#endif
