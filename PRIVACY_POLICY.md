# Privacy Policy for Ruby Touch

**Effective Date:** September 21, 2026  
**Last Updated:** September 21, 2026  
**Application Name:** Ruby Touch  
**Package Name:** `in.aevora.ruby`  
**Developer / Organization:** The Aevora Labs / OpenSwordigo Contributors  
**Source Code:** [https://github.com/TheAevoraLabs/RubyTouch](https://github.com/TheAevoraLabs/RubyTouch)  
**Contact Email:** [aevoralabsin@gmail.com](mailto:aevoralabsin@gmail.com)  

---

## 1. Introduction

The Aevora Labs ("we", "us", or "our") develops and distributes **Ruby Touch** (`in.aevora.ruby`), a standalone, open-source 3D scene studio and terrain modding application for Android. 

We are committed to protecting your privacy. This Privacy Policy explains our practices regarding user data and clarifies how our application operates on your device.

**In brief: Ruby Touch does not collect, store, transmit, track, or sell any personal data or usage metrics. The application functions entirely offline on your local device.**

---

## 2. Information Collection and Use

### Zero Data Collection
Ruby Touch is built from the ground up with a strict zero-data-collection architecture:
- **No Personal Information:** We do not ask for, access, or store your name, email address, phone number, location, contacts, or device identifiers.
- **No User Accounts:** You do not need to register, create an account, or log in to use the application.
- **No Analytics or Telemetry:** There are no analytics libraries, telemetry trackers, crash logging servers, or behavioral monitoring tools embedded in the software.
- **No Advertising:** Ruby Touch does not contain advertisements, tracking pixels, or third-party ad networks.

---

## 3. Device Permissions and Usage Justification

Ruby Touch requests only the minimal device permissions strictly required to perform its core functionality as a local file and 3D level editor.

| Permission | Technical Identifier | Purpose & Justification |
| :--- | :--- | :--- |
| **All Files / External Storage Access** | `android.permission.MANAGE_EXTERNAL_STORAGE`<br>`android.permission.READ_EXTERNAL_STORAGE`<br>`android.permission.WRITE_EXTERNAL_STORAGE` | Required to permit users to select, open, edit, and save local Swordigo modding files (`.scene`, `.swdm`, `.scl`), textures, 3D models, and scene packages across user-specified device folders. |
| **Media Audio & Images** | `android.permission.READ_MEDIA_IMAGES`<br>`android.permission.READ_MEDIA_AUDIO`<br>`android.permission.READ_MEDIA_VIDEO` | Used exclusively to preview and import user-provided terrain textures (PNG, JPG) and audio assets into the 3D scene workspace. |
| **Haptic Feedback** | `android.permission.VIBRATE` | Used solely to deliver tactile haptic vibration when touching 3D vertex handles, dragging geometry, and interacting with editor interface controls. |

**Important Note on Storage:** All files opened, modified, or saved by Ruby Touch remain strictly on your local device storage. Files are never uploaded to any remote server or third-party cloud service.

---

## 4. Network and Internet Access

Ruby Touch does not request or require the `android.permission.INTERNET` permission. The mobile application operates 100% offline. It does not establish outbound network connections, contact remote APIs, or transmit data over the internet.

---

## 5. Third-Party Services and Libraries

Ruby Touch is built using open-source frameworks:
- **Qt Framework (Qt 6 Quick / QML):** Used for rendering the graphical user interface.
- **Lua:** Embedded ANSI C interpreter used exclusively for offline script compilation.
- **OpenGL ES:** Used for rendering 3D graphics locally on your device GPU.

None of these open-source libraries collect or transmit personal information. No third-party software development kits (SDKs) from data brokers, advertising networks, or social platforms are included.

---

## 6. Children's Privacy

Ruby Touch complies with the Children's Online Privacy Protection Act (COPPA) and the General Data Protection Regulation (GDPR). Because our software does not collect, retain, or transmit any personal information whatsoever, it is entirely safe for users of all ages, including children under the age of 13.

---

## 7. Open Source Transparency

Ruby Touch is free and open-source software licensed under the **GNU General Public License v3.0 (GPLv3)**. Our complete source code is publicly accessible and auditable by anyone:
- [https://github.com/TheAevoraLabs/RubyTouch](https://github.com/TheAevoraLabs/RubyTouch)
- Upstream: [https://github.com/TheAevoraLabs/SwordigoDesktop](https://github.com/TheAevoraLabs/SwordigoDesktop)

Security researchers and users are encouraged to review the code to independently verify our privacy commitments.

---

## 8. Changes to This Privacy Policy

We may update this Privacy Policy from time to time to reflect changes in legal requirements or application updates. Any updates will be published directly to this repository with an updated "Last Updated" date. We encourage you to periodically review this page.

---

## 9. Contact Us

If you have any questions, concerns, or inquiries regarding this Privacy Policy or our software, please contact us:

- **Email:** [aevoralabsin@gmail.com](mailto:aevoralabsin@gmail.com)
- **GitHub Issues:** [https://github.com/TheAevoraLabs/RubyTouch/issues](https://github.com/TheAevoraLabs/RubyTouch/issues)
- **Organization:** [https://github.com/TheAevoraLabs](https://github.com/TheAevoraLabs)
