#include "PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

namespace photon_dose_sim
{
	PrimaryGeneratorAction::PrimaryGeneratorAction()
	{
		fParticleGun = new G4ParticleGun(1);

	}

	PrimaryGeneratorAction::~PrimaryGeneratorAction() 
	{
		delete fParticleGun;
	}

	void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
	{
		G4ParticleTable *particleTable=G4ParticleTable::GetParticleTable();
  
  G4String particleName="proton";
  G4ParticleDefinition *particle =particleTable->FindParticle("proton");
  
  G4ThreeVector pos(0.,0.,0.5*cm);
  
  G4ThreeVector mom(0.,0.,1.);
  
    fParticleGun->SetParticlePosition(pos);
       
       
        fParticleGun->SetParticleMomentumDirection(mom);
          
          
          fParticleGun->SetParticleEnergy(999. * MeV);
         
         
         
         fParticleGun->SetParticleDefinition(particle);
         
           fParticleGun->GeneratePrimaryVertex(anEvent);
	}
}
