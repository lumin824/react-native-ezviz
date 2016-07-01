import {
  NativeModules,
  requireNativeComponent
} from 'react-native';

let { EzvizModule } = NativeModules;

export var test = EzvizModule.test;

export var Ezviz = requireNativeComponent('Ezviz');
