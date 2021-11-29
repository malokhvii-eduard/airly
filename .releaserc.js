module.exports = {
  plugins: [
    '@semantic-release/commit-analyzer',
    '@semantic-release/release-notes-generator',
    '@semantic-release/changelog',
    [
      '@semantic-release/git',
      {
        assets: ['CHANGELOG.md'],
        message:
          'chore(release): ${nextRelease.version} [skip ci]\n\n${nextRelease.notes}'
      }
    ]
  ],
  branches: [
    '+([0-9])?(.{+([0-9]),x}).x',
    'master',
    'next',
    { name: 'beta', prerelease: true },
    { name: 'alpha', prerelease: true }
  ]
}
