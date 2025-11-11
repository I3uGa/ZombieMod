# ZombieMod

ZombieMod is a fork of CS2Fixes which is a Metamod plugin with fixes and features aimed but not limited to zombie escape. Instead of reinventing the wheel I'm building on the shoulders of giants and offering the first ZombieMod for CS2 as a module of CS2Fixes. Currently under development - it works. You can run it and let me know of any bugs you find.

## Installation

- Install [Metamod](https://cs2.poggu.me/metamod/installation/)
- Download the [latest release package](https://github.com/JayCroghan/ZombieMod/releases/) - both OS are bundled together.
- Extract the package contents into `game/csgo` on your server
- Configure the plugin cvars as desired in `cfg/cs2fixes/cs2fixes.cfg`, many features are disabled by default
- OPTIONAL: If you want to setup admins, rename `admins.cfg.example` to `admins.cfg` which can be found in `addons/cs2fixes/configs` and follow the instructions within to add admins

## Fixes and Features
You can find the documentation of the fixes and features [here](../../wiki/Home).

## Why add it to CS2Fixes and not a standalone plugin?

The guys at CS2Fixes have already done most of the hard work implementing a real, working CS2 mod with hooks and functions plus the various CS2 fixes included so if I were to make a second plugin people would need two, with a lot more overhead. This way, you can have everything at once. It'll keep the CS2Fixes part separate with an optional ZombieMod module to enable.

## Compilation

```
git clone https://github.com/JayCroghan/ZombieMod/ && cd ZombieMod
git submodule update --init --recursive
```
### Docker (easiest)

Requires Docker to be installed. Produces Linux builds only.

```
docker compose up
```

Copy the contents of `dockerbuild/package/cs2/` to your server's `game/csgo/` directory.

### Manual

#### Requirements
- [Metamod:Source](https://github.com/alliedmodders/metamod-source)
- [AMBuild](https://wiki.alliedmods.net/Ambuild)

#### Linux
```bash
export MMSOURCE_DEV=/path/to/metamod
export HL2SDKCS2=/path/to/sdk/submodule

mkdir build && cd build
python3 ../configure.py --enable-optimize --sdks cs2
ambuild
```

#### Windows

Make sure to run in "x64 Native Tools Command Prompt for VS"

```bash
set MMSOURCE_DEV=\path\to\metamod
set HL2SDKCS2=\path\to\sdk\submodule

mkdir build && cd build
py ../configure.py --enable-optimize --sdks cs2
ambuild
```

Copy the contents of `build/package/cs2/` to your server's `game/csgo/` directory.

#### Running Your server

First make sure this is the command line:

```
-dedicated +dedicated +maxplayers 32 -condebug +exec autoexec.cfg +sv_setsteamaccount <Your Account> -insecure +map de_dust2
```

Not sure if sv_setsteamaccount is required as the autoconfig.cfg below will cancel this out.

Please add the below to your `autoexec.cfg` to prevent crashes

```
sv_lan 0
bot_quota_mode fill
game_mode 0
sv_hibernate_when_empty 0
sv_hibernate_postgame_delay 9999999999999999
```