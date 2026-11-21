# WhatsApp Edited Label Research — Limitations

## 1. Local UI Modification
Changing android:visibility="gone" can hide an Android
view locally, but does not change message edit metadata.

## 2. Recipient-Side Behavior
A sender cannot control the UI rendering of another
person's unmodified official WhatsApp application.

No working recipient-side bypass has been demonstrated.

## 3. APK Signature Verification
Android normally prevents installing an APK signed
with a different certificate as an update to an
existing application.

## 4. Device Restrictions
Research device: Samsung Galaxy M31s

- Android version: 12
- Root access: unavailable
- Bootloader: locked

## 5. Emulator Limitations
The modified APK launched to the welcome screen
but crashed during registration.

A drawable XML replacement was prepared,
but its runtime behavior remains unverified.

## 6. End-to-End Encryption
WhatsApp uses end-to-end encryption.

Changing an Android layout does not bypass encryption
or establish control over message-edit metadata.

## 7. Future Research
- Build an independent Android messaging UI prototype.
- Reproduce edit-indicator rendering in a controlled app.
- Test local view visibility and message-state changes.
- Compare sender-side and recipient-side UI behavior.
- Investigate publicly documented WhatsApp security research.

## Conclusion
The investigation identified an Android UI resource
associated with the Edited label.

The experiment has not established a method to
suppress the label on unmodified official WhatsApp
recipient applications.
