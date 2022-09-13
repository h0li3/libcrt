$Platform = 'x64'
if ($args.Length -gt 0)
{
    $Platform = $args[0].ToLower()
}
if ($Platform -ne 'x64' -and $Platform -ne 'x86') {
    echo 'usage: <x64|x86>'
    exit
}

$LibPath = "$PWD\libs\$Platform"
$ObjPath = "$PWD\libs\objs\$Platform"
$Libcrt_Proj = "$PWD\libcrt\libcrt.vcxproj"

echo 'Building msvcrt.lib...'
$err = lib /def:$LibPath\msvcrt.def /machine:$Platform /out:$LibPath\msvcrt.lib | Out-String
if ($? -eq $false) {
    echo $err
}

echo 'Building msvcp60.lib...'
$err = lib /def:$LibPath\msvcp60.def /machine:$Platform /out:$LibPath\msvcp60.lib | Out-String
if ($? -eq $false) {
    echo $err
}

$objs = [System.IO.Directory]::GetFiles($ObjPath) | select-string '.obj$'

if ($objs -eq $null) {
    echo "'$ObjPath' is empty"
    exit
}

echo 'Building libvcruntime.lib...'
#echo $objs
$err = lib /machine:$Platform /out:$LibPath\libvcruntime_fake.lib $objs | Out-String
if ($? -eq $false) {
    echo $err
}

rm $LibPath\*.exp

echo 'Building libcrt.lib...'
msbuild -p:configuration=Release -p:platform=$Platform "$Libcrt_Proj"
