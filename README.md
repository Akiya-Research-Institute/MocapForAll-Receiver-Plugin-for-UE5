# UE5 plugin and sample project to receive data from MocapForAll

# How to use

- [How to use in English](https://github.com/Akiya-Research-Institute/MocapForAll-Receiver-Plugin-for-UE4/wiki/How-to-use)  
- [日本語版つかいかた](https://github.com/Akiya-Research-Institute/MocapForAll-Receiver-Plugin-for-UE4/wiki/%E4%BD%BF%E3%81%84%E6%96%B9)

# Quick start

In MocapForAll,
- turn on "Settings > Data export > VMT protocol > Send tracking points"
- turn off "Settings > Data export > VMT protocol > Send tracking points > As relative position to HMD"

Make sure
- the port numbers match between MocapForAll and this receiver
- no other application uses the same port

See "Plugins\MocapForAllReceiver\Content\Sample" for exaplmes:
- "BP_Sample1_TransformCubes" shows how to get transforms of tracking points from the OSC messages.
- "BP_Sample2_MetaHuman" shows how to animate a MetaHuman using the transforms of tracking points. Note that you need to import MetaHuman to use this.
- "BP_Sample3_VRM" shows how to animate a VRM model using the transforms of tracking points. Note that you need to install [VRM4U](https://github.com/ruyo/VRM4U) plugin to use this.
- "BP_Sample4_Mannequin_UE4" shows how to animate the UE4 Mannequin using the transforms of tracking points. Note that you need to inport third party template to use this.
- "BP_Sample5_Mannequin_UE5" shows how to animate the UE5 Mannequin using the transforms of tracking points. Note that you need to inport third party template to use this.

# Third party license notice

This repository uses the following open source software:

- [VRM4U](https://github.com/ruyo/VRM4U) created by ruyo
