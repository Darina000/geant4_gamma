//
//  SensitiveDetector.hpp
//  
//
//  Created by Дарья Землянская on 19.07.2020.
//

#ifndef SENSITIVEDETECTOR
#define SENSITIVEDETECTOR

#include<G4VSensitiveDetector.hh>


#include "DetectorConstruction.hh"
#include <vector>
#include "globals.hh"

class G4Step;
class EventAction;
class RunAction;
class G4TouchableHistory;

struct TrackingData{
    G4ThreeVector position;
    
};


class SensitiveDetector: public G4VSensitiveDetector
{

public:
    
  SensitiveDetector(G4String name);
  ~SensitiveDetector();
  G4bool ProcessHits(G4Step *step, G4TouchableHistory *hist);
    
  void Initiaalize(G4HCofThisEvent* HCE);
  void EndOfEvent(G4HCofThisEvent*);
  
    

};

#endif
