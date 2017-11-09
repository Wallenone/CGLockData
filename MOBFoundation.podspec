Pod::Spec.new do |s|
s.name                = "MOBFoundation"
s.version             = "0.0.1"
s.summary             = '自己缝状的智能门锁的公共库'
s.license             = 'www.baidu.com'
s.author              = { "wallen" => "wallenone@sina.cn" }
s.homepage            = 'http://www.baidu.com'
s.source              = { :git => "https://github.com/Wallenone/CGLockData.git", :tag => s.version.to_s }
s.platform            = :ios, '8.0'
s.frameworks          = "CoreBluetooth"
s.vendored_frameworks = 'iOSDFULibrary.framework','LLBluetooth.framework','LLSmartLock.framework','Zip.framework'
end
