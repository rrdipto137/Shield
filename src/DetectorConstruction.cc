#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

namespace photon_dose_sim
{
    G4VPhysicalVolume* DetectorConstruction::Construct()
    {
         G4NistManager* nist = G4NistManager::Instance();

        // world properties
        G4Material* worldMaterial = nist->FindOrBuildMaterial("G4_AIR");
        G4bool checkOverlaps = false;

        G4int worldSizeX = 50*cm;
        G4int worldSizeY = 50*cm;
        G4int worldSizeZ = 50*cm;


        // define worlds
        auto solidWorld = new G4Box("World",
            worldSizeX,                 // default is mm (it seems like)
            worldSizeY,
            worldSizeZ);

        auto logicWorld = new G4LogicalVolume(solidWorld,
            worldMaterial, "World");

        auto physWorld = new G4PVPlacement(nullptr,  // no rotation
            G4ThreeVector(),                           // at (0,0,0)
            logicWorld,                                // its logical volume
            "World",                                   // its name
            nullptr,                                   // its mother  volume
            false,                                     // no boolean operation
            0,                                         // copy number
            checkOverlaps);                            // overlaps checking

        /*/ create envelope
         G4double env_sizeXY = 20*cm, env_sizeZ = 30*cm;
  G4Material* env_mat = nist->FindOrBuildMaterial("G4_WATER");

  // Option to switch on/off checking of volumes overlaps
  //
  //G4bool checkOverlaps = true;
       

        auto solidEnv = new G4Box("Envelope",                    // its name
            0.5 * env_sizeXY, 0.5 * env_sizeXY, 0.5 * env_sizeZ);  // its size

        auto logicEnv = new G4LogicalVolume(solidEnv,  // its solid
            env_mat,                                     // its material
            "Envelope");                                 // its name

        new G4PVPlacement(nullptr,  // no rotation
            G4ThreeVector(),          // at (0,0,0)
            logicEnv,                 // its logical volume
            "Envelope",               // its name
            logicWorld,               // its mother  volume
            false,                    // no boolean operation
            0,                        // copy number
            checkOverlaps);           // overlaps checking

        */

        // First Detector
        G4Material*detector1Material = nist->FindOrBuildMaterial("G4_WATER");
        G4double detector1SizeX = worldSizeX ;
        G4double detector1SizeY = worldSizeY ;
        G4double detector1SizeZ = 0.4 * cm;
        G4ThreeVector detector1Pos = G4ThreeVector(0, 0, 5 * cm);

        auto solidDetector1 = new G4Box("Detector1",
            detector1SizeX,
            detector1SizeY,
            detector1SizeZ);

        auto logicDetector1 = new G4LogicalVolume(solidDetector1,
            detector1Material,
            "Detector1");

        new G4PVPlacement(nullptr,    // rotation
            detector1Pos,              // position
            logicDetector1,           // its logical volume
            "Detector1",              // its name
            logicWorld,               // its mother  volume
            false,                    // boolean operation
            0,                        // copy number
            checkOverlaps);           // overlaps checking

      
      
      
            //Shield
  
      
         G4Material* leadMaterial = nist->FindOrBuildMaterial("G4_Pb");
        G4double leadSizeX = worldSizeX ;
        G4double leadSizeY = worldSizeY ;
        G4double leadSizeZ =  5* cm;  // Adjust the thickness of the lead shield as needed

        auto solidLead = new G4Box("LeadShield",
            leadSizeX,
            leadSizeY,
            leadSizeZ);

        auto logicLead = new G4LogicalVolume(solidLead,
            leadMaterial,
            "LeadShield");

        G4ThreeVector leadPos = G4ThreeVector(0, 0, 22.5 * cm); // Position lead shield between the detectors
        new G4PVPlacement(nullptr,
            leadPos,
            logicLead,
            "LeadShield",
            logicWorld,
            false,
            0,
            checkOverlaps);
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // Second Detector (45 cm apart)
        G4Material*detector2Material = nist->FindOrBuildMaterial("G4_WATER");
        G4double detector2SizeX = worldSizeX ;
        G4double detector2SizeY = worldSizeY ;
        G4double detector2SizeZ = 0.4 * cm;
        G4ThreeVector detector2Pos2 = G4ThreeVector(0, 0, 50 * cm); // 50 cm apart in the z-direction

        auto solidDetector2 = new G4Box("Detector2",
            detector2SizeX,
            detector2SizeY,
            detector2SizeZ);

        auto logicDetector2 = new G4LogicalVolume(solidDetector2,
            detector2Material,
            "Detector2");

        new G4PVPlacement(nullptr,    // rotation
            detector2Pos2,             // position
            logicDetector2,           // its logical volume
            "Detector2",              // its name
            logicWorld,               // its mother  volume
            false,                    // boolean operation
            1,                        // copy number (different than the first detector)
            checkOverlaps);           // overlaps checking

        

        // Set scoring volumes
        fScoringVolume1= logicDetector2;
         fScoringVolume2= logicDetector1;
        
       
        return physWorld;
    }
}

