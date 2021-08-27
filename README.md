# UE5 plugin and sample project to receive data from MocapForAll

# How to use
For details, see  
[How to use in English](https://github.com/Akiya-Research-Institute/MocapForAll-Receiver-Plugin-for-UE5/wiki/How-to-use)  
[日本語版つかいかた](https://github.com/Akiya-Research-Institute/MocapForAll-Receiver-Plugin-for-UE5/wiki/%E4%BD%BF%E3%81%84%E6%96%B9)

In MocapForAll,
- turn on "Settings > Data export > VMT protocol > Send tracking positions" or "Send bones"
- turn off "Settings > Data export > VMT protocol > Send tracking positions > As relative position to HMD"

Make sure
- the port numbers match between MocapForAll and this receiver
- no other application uses the same port

See "Plugins\MocapForAllReceiver\Content\Sample" for exaplmes:
- "BP_Sample1_TransformCubes" shows how to get transforms of tracking points from the OSC messages.
- "BP_Sample2_TrackerToControlRig_MetaHumanPreview" shows how to animate a MetaHuman using the transforms of tracking points. This should be used with "Send bones" option in MocapForAll. Note that you need to import MetaHuman to use this.
- "BP_Sample3_TrackerToControlRig_VRM" is an example to show how to animate a VRM using the transforms of tracking points. This should be used with "Send tracking positions" option in MocapForAll.

# NOTICE

This repository uses the following open source software:
- [ueOSC](https://github.com/HAL9HARUKU/ueOSC) created by HAL9HARUKU
- [VMC4UE](https://github.com/HAL9HARUKU/VMC4UE) created by HAL9HARUKU
- [VRM4U](https://github.com/ruyo/VRM4U) created by ruyo
