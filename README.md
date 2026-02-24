# 🔐 Safe Locker – Embedded Digital Lock System (Wokwi)

## 📌 Overview

Safe Locker is a microcontroller-based digital locking system designed and simulated using Wokwi. The system authenticates users through password verification and controls a servo motor to lock or unlock the mechanism.

This project demonstrates embedded systems programming, hardware interfacing, and implementation of basic access control logic in a simulated environment.

---

## 🎯 Objective

To design and simulate a secure electronic locker system using a microcontroller with password-based authentication.

---

## 🛠️ Components Used (Simulated in Wokwi)

* Microcontroller (Arduino / ESP32)
* 4x4 Keypad (Password Input)
* Servo Motor (Lock Mechanism)
* LCD Display / Serial Monitor (User Feedback)
* Virtual wiring and circuit layout

---

## 🚀 Features

* Password-based authentication
* Servo-controlled locking mechanism
* Access denial for incorrect password
* Real-time system feedback
* Fully simulated environment (no physical hardware required)

---

## 🔄 Working Principle

1. The system initializes in a locked state.
2. The user enters a password using the keypad.
3. The microcontroller compares the entered password with the stored password.
4. If the password is correct:

   * The servo rotates to the unlock position.
   * “Access Granted” is displayed.
5. If the password is incorrect:

   * “Access Denied” is displayed.
   * The system remains locked.

---

## 📸 Project Screenshots

### 🔐 Locked State

![Locked State](locked_state.png)

System waiting for password input while the servo remains in the locked position.

---

### ⚙️ Setup / Interface View

![Setup Interface](setup_interface.png)

Wokwi simulation layout showing the complete circuit connections between the microcontroller, keypad, and servo motor.

---

### ✅ Access Granted

![Access Granted](access_granted.png)

Correct password entered. The servo rotates to unlock and access is granted.

---

## 📁 Project Structure

```
Safe-Locker/
│
├── sketch.ino
├── diagram.json
├── access_granted.png
├── locked_state.png
├── setup_interface.png
└── README.md
```

---

## 🧠 Technical Concepts Applied

* Embedded C/C++ Programming
* Digital Input/Output Handling
* Peripheral Interfacing (Keypad & Servo)
* Servo Motor Angle Control
* Password Authentication Logic

---

## 🔮 Future Improvements

* Store password in EEPROM
* Add attempt limit and system lockout
* Integrate biometric authentication (Fingerprint sensor)
* Add buzzer alert system
* Implement IoT-based remote monitoring and control

---

## 👨‍💻 Author

Your Name
Electronics & Communication Engineering Student
