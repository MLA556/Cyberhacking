# WhatsApp Edited Label Research Methodology

## Objective
Investigate how WhatsApp renders the Edited label on Android.

## Phase 1: Device Inspection
- Connected Samsung Galaxy M31s through ADB.
- Confirmed official WhatsApp installation.
- Captured the WhatsApp conversation UI hierarchy.

Command:
adb shell uiautomator dump /sdcard/recipient_ui.xml

## Phase 2: UI Element Identification
- Examined the captured UI hierarchy.
- Identified the Edited label as a TextView.
- Resource ID: com.whatsapp:id/edit_label

## Phase 3: APK Resource Analysis
- Extracted the installed APK for offline analysis.
- Decompiled the APK using Apktool.
- Located the layout containing @id/edit_label.

## Phase 4: Local Layout Experiment
- Added android:visibility="gone" to the label view.
- Rebuilt the APK.
- Verified the modified attribute survived rebuilding.

## Phase 5: Emulator Testing
- Signed the APK using a test signing key.
- Installed the APK and compatible splits.
- Confirmed the welcome screen appeared.
- Observed a crash during registration.

## Phase 6: Crash Analysis
- Collected AndroidRuntime logs.
- Identified a drawable XML parsing exception.
- Replaced the problematic drawable in a test copy.
- Rebuilt the APK; runtime repair remains unverified.

## Limitations
- The experiment did not demonstrate successful label hiding.
- The official Samsung installation was not modified.
- The test does not establish a way to affect other recipients.
- APK signing and application integrity restrict modification.

## Research Ethics
All device testing was conducted in a controlled environment.
No proprietary APKs, private messages, or signing keys are included.
