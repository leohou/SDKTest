Pod::Spec.new do |s|
  s.name = "WeSaiSDK"
  s.version = "1.0"
  s.summary = "WeSaiSDK"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"wesaiPublic"=>"app@wesai.com"}
  s.homepage = "https://github.com/leohou/SDKTest"
  s.description = "TODO:  Add long description of the pod here."
  s.frameworks = ["UIKit", "Foundation", "SystemConfiguration", "CoreGraphics", "StoreKit",'AdSupport','Security','CoreTelephony','WebKit']
  s.xcconfig = {"OTHER_LDFLAGS"=>"-lObjC"}
  s.source   = { :git => 'https://github.com/leohou/SDKTest.git'}

  s.ios.deployment_target    = '8.0'
  s.ios.vendored_framework   = 'ios/WSUserSDK.framework'

  s.dependency 'ShareSDK3/ShareSDKPlatforms/WeChat', '~> 3.3.2'
  s.dependency 'Masonry', '~> 0.6.1'
  s.dependency 'JSONModel', '~> 1.2.0'
  s.dependency 'FMDB'
  s.dependency 'IQKeyboardManager' ,'5.0.6'
  s.ios.resource=['ios/Resource/**/*.{xcassets,wav,mp3,xib,txt,cer,plist}']
end
