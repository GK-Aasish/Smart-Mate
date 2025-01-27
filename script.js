// Static values for testing
let temperature = 30; // Example: greater than threshold
let humidity = 50;
let motorStatus = "ON"; // Change to "OFF" for testing

const tempElement = document.getElementById("temperature");
const humidityElement = document.getElementById("humidity");
const motorButton = document.getElementById("motor-status");

function updateUI() {
  // Update temperature
  if (temperature > 28) {
    tempElement.className = "status red";
    tempElement.textContent = `${temperature}°C (Heat Alert)`;
  } else {
    tempElement.className = "status normal";
    tempElement.textContent = `${temperature}°C (Normal)`;
  }

  // Update humidity
  humidityElement.textContent = `${humidity}%`;

  // Update motor status
  if (motorStatus === "ON") {
    motorButton.className = "status-button on";
    motorButton.textContent = "ON";
  } else {
    motorButton.className = "status-button off";
    motorButton.textContent = "OFF";
  }
}

// Simulate fetching data from an ESP32 device
setInterval(() => {
  // Example: Simulate data updates
  temperature = Math.random() * 10 + 25; // Random temp between 25 and 35
  humidity = Math.random() * 20 + 40; // Random humidity between 40 and 60
  motorStatus = Math.random() > 0.5 ? "ON" : "OFF";

  updateUI();
}, 5000); // Update every 5 seconds

// Initial UI update
updateUI();
