import {
  NativeModules,
  requireNativeComponent
} from 'react-native';

let { EzvizModule } = NativeModules;

export var getCameraList = EzvizModule.getCameraList;
export var getDeviceInfo = EzvizModule.getDeviceInfo;
export var getDeviceList = EzvizModule.getDeviceList;
export var controlPTZ = EzvizModule.controlPTZ;

export var EZPTZCommand = {
  EZPTZCommandLeft: EzvizModule.EZPTZCommand_EZPTZCommandLeft,
  EZPTZCommandRight: EzvizModule.EZPTZCommand_EZPTZCommandRight,
  EZPTZCommandUp: EzvizModule.EZPTZCommand_EZPTZCommandUp,
  EZPTZCommandDown: EzvizModule.EZPTZCommand_EZPTZCommandDown,
};

export var EZPTZAction = {
  EZPTZActionSTART: EzvizModule.EZPTZAction_EZPTZActionSTART,
  EZPTZActionSTOP: EzvizModule.EZPTZAction_EZPTZActionSTOP
};

export var Ezviz = requireNativeComponent('Ezviz');
