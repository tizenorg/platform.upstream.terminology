Name:           terminology
Version:        0.1
Release:        1
License:        BSD 2-clause
Summary:        Terminal Program
Url:            http://www.enlightenment.org/
Group:          Graphics/X11
Source0:        %{name}-%{version}.tar.bz2
Source1001: 	terminology.manifest

BuildRequires:  pkgconfig(ecore)
BuildRequires:  pkgconfig(ecore-imf)
BuildRequires:  pkgconfig(ecore-imf-evas)
BuildRequires:  pkgconfig(ecore-input)
BuildRequires:  pkgconfig(edje)
BuildRequires:  pkgconfig(eet)
BuildRequires:  pkgconfig(efreet)
BuildRequires:  pkgconfig(eina)
BuildRequires:  pkgconfig(elementary)
BuildRequires:  pkgconfig(emotion)
BuildRequires:  pkgconfig(evas)

%description
Terminilogy Terminal program.
%prep
%setup -q
cp %{SOURCE1001} .


%build
%autogen
%configure
make %{?_smp_mflags}

%install
%make_install

%files
%manifest %{name}.manifest
%defattr(-,root,root,-)
%license COPYING
/usr/bin/terminology
/usr/share/applications/terminology.desktop
/usr/share/icons/terminology.png
/usr/share/terminology/fonts
/usr/share/terminology
