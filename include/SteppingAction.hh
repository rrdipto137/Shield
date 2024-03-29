#ifndef PhotonDoseSimSteppingAction_h
#define PhotonDoseSimSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class G4LogicalVolume;

namespace photon_dose_sim
{

class EventAction;

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction() override = default;

    // method from the base class
    void UserSteppingAction(const G4Step*) override;

  private:
    EventAction* fEventAction1 = nullptr;
    EventAction* fEventAction2 = nullptr;
    G4LogicalVolume* fScoringVolume1 = nullptr;
    G4LogicalVolume* fScoringVolume2 = nullptr;
};

}


#endif
