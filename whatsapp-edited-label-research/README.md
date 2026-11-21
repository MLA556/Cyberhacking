# WhatsApp Edited Label — UI Security Research

## Research Objective
Investigate how WhatsApp displays the "Edited" label on Android and whether its visibility can be changed locally.

## Test Environment
- Samsung Galaxy M31s — Android 12
- Official WhatsApp version 2.26.39.79
- Kali Linux and Windows 11
- Android Debug Bridge (ADB)
- Apktool 3.0.3
- Android Emulator

## Technical Findings
- Identified the Android UI resource: `com.whatsapp:id/edit_label`
- Identified the view class: `android.widget.TextView`
- Located the corresponding `WDSTextView` XML layout
- Experimentally added `android:visibility="gone"`
- Rebuilt and signed a modified APK
- Installed the modified APK set on an Android emulator
- Encountered a drawable XML resource crash during registration

## Current Result
The XML modification was verified inside the rebuilt APK.

The modified application's ability to hide the Edited label during a real conversation has NOT been verified.

No method has been demonstrated to hide the Edited label on other recipients' unmodified official WhatsApp applications.

## Research Scope
Local UI analysis, Android resource inspection, APK rebuilding, and controlled testing.

## Disclaimer
Independent security research. Not affiliated with or endorsed by WhatsApp or Meta.

This repository does not distribute proprietary WhatsApp APKs, private messages, or signing keys.
