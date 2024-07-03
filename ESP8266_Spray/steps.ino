void runStep() {
  // Pump    
  if (currentStep == "pumpon") {
    runPump();        
    currentStep = "";
  }
}